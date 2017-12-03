//
// Created on 07/11/2017.
//

#include <random>
#include <sstream>
#include "PlayState.h"
#include "../GUI/GUIConstants.h"
#include "../WorldLogic/Entities.h"
#include "../PlayerLogic/Skills.h"
#include "../PlayerLogic/PlayerLogicConstants.h"
#include "../PlayerLogic/CharacterFactory.h"
#include "../PlayerLogic/Races.h"
#include "../PlayerLogic/Classes.h"

#define STAT_CARD_PATH_INACTIVE "./res/StatCardInactive.png"
#define STAT_CARD_PATH_ACTIVE "./res/StatCardActive.png"
#define STAT_CARD_PATH_DEAD "./res/StatCardDead.png"
#define STAT_CARD_PATH_WIN "./res/StatCardWin.png"

PlayState::PlayState(vector<unique_ptr<Race>> players) : _inGameBg(IN_GAME_DEFAULT_BG_PATH), _playerStats(NB_PLAYERS),
                                                         _players(move(players))
{
    random_device r;
    default_random_engine randomEngine(r());
    uniform_int_distribution<int> uniformIntDistribution(1, 4); // between 1 and 4 included
    int randNb = uniformIntDistribution(randomEngine);
    switch (randNb)
    {
        case 1:
            _inGameBg = Background(IN_GAME_BG_1_PATH);
            break;
        case 2:
            _inGameBg = Background(IN_GAME_BG_2_PATH);
            break;
        case 3:
            _inGameBg = Background(IN_GAME_BG_3_PATH);
            break;
        case 4:
            _inGameBg = Background(IN_GAME_BG_4_PATH);
            break;
        default:
            break;
    }
    _currentPlayer = 0;
}

void PlayState::onEnter()
{
    _inGameBg.init();

    _dungeon.generate();

    _dungeon.init();

    for (int i = 0; i < NB_PLAYERS; i++)
    {
        ostringstream playerIdentityString;
        playerIdentityString << _players[i]->getName() << " (" << _players[i]->RaceToString() << ", "
                       << _players[i]->ClassToString() << ")";
        string playerIdentity = playerIdentityString.str();

        ostringstream attackString;
        attackString << "Attack: " << _players[i]->getAttack()->getValue() << " / "
                     << _players[i]->getAttack()->getMaxValue();
        string attack = attackString.str();

        ostringstream defenseString;
        defenseString << "Defense: " << _players[i]->getDefense()->getValue() << " / "
                     << _players[i]->getDefense()->getMaxValue();
        string defense = defenseString.str();

        ostringstream agilityString;
        agilityString << "Agility: " << _players[i]->getAgility()->getValue() << " / "
                      << _players[i]->getAgility()->getMaxValue();
        string agility = agilityString.str();

        ostringstream lifeString;
        lifeString << "Life: " << _players[i]->getLife()->getValue() << " / "
                      << _players[i]->getLife()->getMaxValue();
        string life = lifeString.str();


        string headTilePath;
        switch (_players[i]->getClass())
        {
            case thief:
                headTilePath = HEAD_THIEF_PATH;
                break;
            case priest:
                headTilePath = HEAD_PRIEST_PATH;
                break;
            case assassin:
                headTilePath = HEAD_ASSASSIN_PATH;
                break;
            case paladin:
                headTilePath = HEAD_PALADIN_PATH;
                break;
            default:
                headTilePath = HEAD_PALADIN_PATH;
                break;
        }
        string bodyTilePath;
        switch (_players[i]->getRace())
        {
            case barbarian:
                bodyTilePath = BODY_BARBARIAN_PATH;
                break;
            case human:
                bodyTilePath = BODY_HUMAN_PATH;
                break;
            case elf:
                bodyTilePath = BODY_ELF_PATH;
                break;
            case dwarf:
                bodyTilePath = BODY_DWARF_PATH;
                break;
            default:
                bodyTilePath = BODY_HUMAN_PATH;
                break;
        }

        _playerStats[i] = new StatCard(STAT_CARD_PATH_INACTIVE, WINDOW_WIDTH - STAT_CARD_WIDTH,
                                       350 + STAT_CARD_HEIGHT * i, STAT_CARD_WIDTH, STAT_CARD_HEIGHT, playerIdentity,
                                       attack, defense, agility, life, headTilePath.c_str(), bodyTilePath.c_str());

        _playerStats[i]->init();
    }

    _playerStats[_currentPlayer]->setTile(STAT_CARD_PATH_ACTIVE);
}

void PlayState::handleEvents()
{
    SDL_Event event{};
    while (SDL_PollEvent(& event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            GameEngine::get().Quit();
            break;
        }

        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            _dungeon.handleEvent(& event);
        }
    }
}

void PlayState::update()
{
    _dungeon.update();
}

bool PlayState::fightMonster(Monster * monster)
{
    int monster_life = monster->getLife();
    if (_players[_currentPlayer]->getDefense()->getValue() >= monster->getAttack() && monster->getDefense() >= _players[_currentPlayer]->getAttack()->getValue())
    {
            printf("Impossible fight\n");
            return  false;
    }
    while (monster->getLife() > 0 && _players[_currentPlayer]->getLife()->getValue() > 0)
    {
        int pAttackValue = _players[_currentPlayer]->getAttack()->getValue() - monster->getDefense();
        if (pAttackValue < 0) {pAttackValue = 0;}
        monster->alterLife(- pAttackValue );
        printf("Player attack : %d\nMonster have %d life points.\n", pAttackValue, monster->getLife() );
        if (monster->getLife() > 0)
        {
            random_device r;
            default_random_engine randomEngine(r());
            uniform_int_distribution<int> uniformIntDistribution(1, 100); // between 1 and 4 included
            int randNb = uniformIntDistribution(randomEngine);

            if (randNb > _players[_currentPlayer]->getAgility()->getValue())
            {
                int mAttackValue = monster->getAttack() - _players[_currentPlayer]->getDefense()->getValue();
                if (mAttackValue < 0) {mAttackValue = 0;}
                _players[_currentPlayer]->getLife()->alterPoints(- mAttackValue);
                printf("Monster attack : %d\nPlayer have %d life points.\n", mAttackValue, _players[_currentPlayer]->getLife()->getValue());
            } else
            {
                printf("Dodge !!\n");
            }
        }
    }
    if (monster->getLife() <= 0)
    {
        random_device r;
        default_random_engine randomEngine(r());
        uniform_int_distribution<int> uniformIntDistribution(1, 3); // between 1 and 4 included
        int randNb = uniformIntDistribution(randomEngine);
        switch (randNb)
        {
            case 1:
                _players[_currentPlayer]->getAttack()->alterPoints(monster->getLevel());
                break;
            case 2:
                _players[_currentPlayer]->getDefense()->alterPoints(monster->getLevel());
                break;
            case 3:
                _players[_currentPlayer]->getAgility()->alterPoints(monster->getLevel());
                break;
            default:
                break;
        }
        if (monster->isBoss())
        {
            printf("%s WINS !!\n", _players[_currentPlayer]->getName());
            monster->alterLife(+ monster_life);
            return true;
        }
    }
    monster->alterLife(- monster->getLife());
    monster->alterLife(+ monster_life);
    return false;
}

void PlayState::fleeMonster()
{
    random_device r;
    default_random_engine randomEngine(r());
    uniform_int_distribution<int> uniformIntDistribution(1, 4); // between 1 and 4 included
    int randNb = uniformIntDistribution(randomEngine);

    if (randNb == 1)
    {
        _players[_currentPlayer]->getLife()->alterPoints(- (_players[_currentPlayer]->getLife()->getValue()/2));
    }
}

void PlayState::takeTrap(Trap * trap)
{
    switch (trap->getTargetSkill())
    {
        case ATTACK:
            _players[_currentPlayer]->getAttack()->alterPoints(- trap->getDamage());
            break;
        case DEFENSE:
            _players[_currentPlayer]->getDefense()->alterPoints(- trap->getDamage());
            break;
        case AGILITY:
            _players[_currentPlayer]->getAgility()->alterPoints(- trap->getDamage());
            break;
        case LIFE:
            _players[_currentPlayer]->getLife()->alterPoints(- trap->getDamage());
            break;
        default:
            break;
    }
}

void PlayState::takeTreasure(Treasure * treasure)
{
    switch (treasure->getTargetSkill())
    {
        case ATTACK:
            _players[_currentPlayer]->getAttack()->alterPoints(treasure->getBonus());
            break;
        case DEFENSE:
            _players[_currentPlayer]->getDefense()->alterPoints(treasure->getBonus());
            break;
        case AGILITY:
            _players[_currentPlayer]->getAgility()->alterPoints(treasure->getBonus());
            break;
        case LIFE:
            _players[_currentPlayer]->getLife()->alterPoints(treasure->getBonus());
            break;
        default:
            break;
    }
}

void PlayState::updateCurrentPlayer(Room * room, bool accept)
{
    bool winOrDead = false;
    if (room->getType() == MONSTER && accept)
    {
        auto monster = (Monster *) room;
        if (fightMonster(monster))
        {
            winOrDead = true;
            _playerStats[_currentPlayer]->setTile(STAT_CARD_PATH_WIN);
        }
    }
    else if (room->getType() == MONSTER && !accept)
    {
        fleeMonster();
    }
    else if (room->getType() == TRAP)
    {
        auto * trap = (Trap *) room;
        takeTrap(trap);
    }
    else if (room->getType() == TREASURE)
    {
        auto * treasure = (Treasure *) room;
        takeTreasure(treasure);
    }

    if (_players[_currentPlayer]->getLife()->getValue() <= 0)
    {
        Race * newPlayer = CharacterFactory::get().createCharacter(_players[_currentPlayer]->getRace(),
                                                                   _players[_currentPlayer]->getClass(),
                                                                   _players[_currentPlayer]->getName());
        _players[_currentPlayer].reset(newPlayer);
        winOrDead = true;
        _playerStats[_currentPlayer]->setTile(STAT_CARD_PATH_DEAD);
    }
    else
    {
        _players[_currentPlayer]->getLife()->alterPoints(LIFE_INCREASE);
    }

    ostringstream attackString;
    attackString << "Attack: " << _players[_currentPlayer]->getAttack()->getValue() << " / "
                 << _players[_currentPlayer]->getAttack()->getMaxValue();
    string attack = attackString.str();

    ostringstream defenseString;
    defenseString << "Defense: " << _players[_currentPlayer]->getDefense()->getValue() << " / "
                  << _players[_currentPlayer]->getDefense()->getMaxValue();
    string defense = defenseString.str();

    ostringstream agilityString;
    agilityString << "Agility: " << _players[_currentPlayer]->getAgility()->getValue() << " / "
                  << _players[_currentPlayer]->getAgility()->getMaxValue();
    string agility = agilityString.str();

    ostringstream lifeString;
    lifeString << "Life: " << _players[_currentPlayer]->getLife()->getValue() << " / "
               << _players[_currentPlayer]->getLife()->getMaxValue();
    string life = lifeString.str();

    _playerStats[_currentPlayer]->update(attack, defense, agility, life);

    if (!winOrDead)
    {
        _playerStats[_currentPlayer]->setTile(STAT_CARD_PATH_INACTIVE);
    }
    _currentPlayer = (_currentPlayer + 1) % NB_PLAYERS;
    _playerStats[_currentPlayer]->setTile(STAT_CARD_PATH_ACTIVE);
    printf("Player changed: now %d\n", _currentPlayer);
}

void PlayState::render()
{
    _inGameBg.render();
    for (int i = 0; i < NB_PLAYERS; i++)
    {
        _playerStats[i]->render();
    }
    _dungeon.render();
}

void PlayState::onExit()
{
    _dungeon.cleanup();
    for (int i = 0; i < NB_PLAYERS; i++)
    {
        _playerStats[i]->cleanup();
    }
    _inGameBg.cleanup();
}

PlayState::~PlayState()
{
    for (auto statCard : _playerStats)
    {
        delete statCard;
    }
}
