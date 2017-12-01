//
// Created on 11/11/2017.
//

#include <random>
#include "Dungeon.h"
#include "Entities.h"
#include "Monster.h"
#include "Trap.h"
#include "../PlayerLogic/Skills.h"
#include "Treasure.h"
#include "../GUI/GUIConstants.h"
#include "../Core/GameStateManager.h"
#include "../Core/PlayState.h"

#define CARDS_PER_LINE 6
#define MONSTER_1_IMAGE_PATH "./res/monsterImage_1.png"
#define MONSTER_2_IMAGE_PATH "./res/monsterImage_2.png"
#define MONSTER_3_IMAGE_PATH "./res/monsterImage_3.png"
#define MONSTER_4_IMAGE_PATH "./res/monsterImage_4.png"
#define MONSTER_5_IMAGE_PATH "./res/monsterImage_5.png"
#define MONSTER_6_IMAGE_PATH "./res/monsterImage_6.png"
#define MONSTER_7_IMAGE_PATH "./res/monsterImage_7.png"
#define MONSTER_8_IMAGE_PATH "./res/monsterImage_8.png"
#define MONSTER_9_IMAGE_PATH "./res/monsterImage_9.png"
#define MONSTER_10_IMAGE_PATH "./res/monsterImage_10.png"
#define MONSTER_11_IMAGE_PATH "./res/monsterImage_11.png"
#define MONSTER_12_IMAGE_PATH "./res/monsterImage_12.png"
#define MONSTER_13_IMAGE_PATH "./res/monsterImage_13.png"
#define MONSTER_14_IMAGE_PATH "./res/monsterImage_14.png"
#define MONSTER_15_IMAGE_PATH "./res/monsterImage_15.png"
#define BOSS_1_IMAGE_PATH "./res/bossImage_1.png"
#define BOSS_2_IMAGE_PATH "./res/bossImage_2.png"
#define BOSS_3_IMAGE_PATH "./res/bossImage_3.png"
#define BOSS_4_IMAGE_PATH "./res/bossImage_4.png"
#define BOSS_5_IMAGE_PATH "./res/bossImage_5.png"
#define TREASURE_1_IMAGE_PATH "./res/treasureImage_1.png"
#define TREASURE_2_IMAGE_PATH "./res/treasureImage_2.png"
#define TREASURE_3_IMAGE_PATH "./res/treasureImage_3.png"
#define TREASURE_4_IMAGE_PATH "./res/treasureImage_4.png"
#define TREASURE_5_IMAGE_PATH "./res/treasureImage_5.png"
#define TREASURE_6_IMAGE_PATH "./res/treasureImage_6.png"
#define TREASURE_7_IMAGE_PATH "./res/treasureImage_7.png"
#define TRAP_1_IMAGE_PATH "./res/trapImage_1.png"
#define TRAP_2_IMAGE_PATH "./res/trapImage_2.png"
#define TRAP_3_IMAGE_PATH "./res/trapImage_3.png"
#define TRAP_4_IMAGE_PATH "./res/trapImage_4.png"
#define TRAP_5_IMAGE_PATH "./res/trapImage_5.png"
#define TRAP_6_IMAGE_PATH "./res/trapImage_6.png"
#define TRAP_7_IMAGE_PATH "./res/trapImage_7.png"

Dungeon::Dungeon()
{
    _playedDeck.reserve(NB_CARDS_INGAME);
    _allRooms.reserve(NB_CARDS);
    _activated = true;
    _lastVisitedCard = nullptr;
    _returnedCardsCount = 0;

    // 0 CARDS
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "PLANTE VERTE", "Vous n'allez quand meme pas vous en prendre a un pauvre petite plante inoffensive ?", MONSTER_1_IMAGE_PATH, 1, 2, 20, 1)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "PLANTE VERTE", "Vous n'allez quand meme pas vous en prendre a un pauvre petite plante inoffensive ?", MONSTER_1_IMAGE_PATH, 1, 2, 20, 1)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "LOUVETEAU", "Grrraou !! Grrraou !! Oh qu'il est mignon. Ce serait une honte de tuer cette pauvre petite creature uniquement pour gagner des points d'experience.", MONSTER_2_IMAGE_PATH, 5, 2, 25, 1)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "LOUVETEAU", "Grrraou !! Grrraou !! Oh qu'il est mignon. Ce serait une honte de tuer cette pauvre petite creature uniquement pour gagner des points d'experience.", MONSTER_2_IMAGE_PATH, 5, 2, 25, 1)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "BEBE ORC", "Il aurait pu devenir un grand chef de guerre si sa maman ne l'avait pas laisse sans surveillance...", MONSTER_3_IMAGE_PATH, 5, 2, 10, 1)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "BEBE ORC", "Il aurait pu devenir un grand chef de guerre si sa maman ne l'avait pas laisse sans surveillance...", MONSTER_3_IMAGE_PATH, 5, 2, 10, 1)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "JEUNE LOUP", "En regardant ce loup dans les yeux, on se rend compte qu'il a l'oeil du tigre.", MONSTER_4_IMAGE_PATH, 30, 10, 20, 2)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "JEUNE LOUP", "En regardant ce loup dans les yeux, on se rend compte qu'il a l'oeil du tigre.", MONSTER_4_IMAGE_PATH, 30, 10, 20, 2)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "ORC ADOLESCENT", "Sa conseillere d'orientation ne serait pas fiere de le voir trainer ici plutot que d'aller en cours ...", MONSTER_5_IMAGE_PATH, 20, 5, 40, 2)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "ORC ADOLESCENT", "Sa conseillere d'orientation ne serait pas fiere de le voir trainer ici plutot que d'aller en cours ...", MONSTER_5_IMAGE_PATH, 20, 5, 40, 2)));
    // 10 CARDS
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "JEUNE GRIZZLY", "Il semblerait que ce soit une femelle, ... du coup on dit une grizzlie ?", MONSTER_6_IMAGE_PATH, 15, 10, 60, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "JEUNE GRIZZLY", "Il semblerait que ce soit une femelle, ... du coup on dit une grizzlie ?", MONSTER_6_IMAGE_PATH, 15, 10, 60, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "BONHOMME DE NEIGE", "Qui aurait cru que les bonhommes de neiges puissent devenir aussi agressifs ?", MONSTER_7_IMAGE_PATH, 10, 0, 200, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "BONHOMME DE NEIGE", "Qui aurait cru que les bonhommes de neiges puissent devenir aussi agressifs ?", MONSTER_7_IMAGE_PATH, 10, 0, 200, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "BANDIT DE GRAND CHEMIN", "Cet homme est une legende dans le milieu, vous auriez peut-etre du faire un detour ...", MONSTER_8_IMAGE_PATH, 15, 5, 50, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "BANDIT DE GRAND CHEMIN", "Cet homme est une legende dans le milieu, vous auriez peut-etre du faire un detour ...", MONSTER_8_IMAGE_PATH, 15, 5, 50, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "OURS DES CAVERNES", "Papa grizzly n'a pas l'air ravi de vous voir sur son territoire de chasse ...", MONSTER_9_IMAGE_PATH, 20, 15, 70, 4)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "OURS DES CAVERNES", "Papa grizzly n'a pas l'air ravi de vous voir sur son territoire de chasse ...", MONSTER_9_IMAGE_PATH, 20, 15, 70, 4)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "VAMPIRE", "Vous n'auriez peut-etre pas du manger tout l'ail de vos provisions lors de votre dernier casse-croute ...", MONSTER_10_IMAGE_PATH, 20, 20, 40, 4)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "VAMPIRE", "Vous n'auriez peut-etre pas du manger tout l'ail de vos provisions lors de votre dernier casse-croute ...", MONSTER_10_IMAGE_PATH, 20, 20, 40, 4)));
    // 20 CARDS
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "ARAIGNEE GEANTE", "Le vieux sorcier vous avait pourtant prevenu : il est interdit d'aller dans la foret interdite !", MONSTER_11_IMAGE_PATH, 25, 10, 50, 5)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "ARAIGNEE GEANTE", "Le vieux sorcier vous avait pourtant prevenu : il est interdit d'aller dans la foret interdite !", MONSTER_11_IMAGE_PATH, 25, 10, 50, 5)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "LOUP ALPHA", "Le chef de la meute. Peut-etre que tuer sa progeniture n'etait pas un tres bonne idee. Les loups du nord se rappellent de tout ...", MONSTER_12_IMAGE_PATH, 30, 5, 70, 5)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "LOUP ALPHA", "Le chef de la meute. Peut-etre que tuer sa progeniture n'etait pas un tres bonne idee. Les loups du nord se rappellent de tout ...", MONSTER_12_IMAGE_PATH, 30, 5, 70, 5)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "SQUELETTE VIVANT", "Pour tuer un squelette, il faut viser le coeur. Enfin, c'est ce qu'on dit ...", MONSTER_13_IMAGE_PATH, 40, 10, 50, 6)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "SQUELETTE VIVANT", "Pour tuer un squelette, il faut viser le coeur. Enfin, c'est ce qu'on dit ...", MONSTER_13_IMAGE_PATH, 40, 10, 50, 6)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "HORDE DE ZOMBIES", "Ils sont lents. Ils ne font pas tres mal. Ils ne sont pas resistants. Mais ils nombreux, tres nombreux, vraiment tres nombreux ...", MONSTER_14_IMAGE_PATH, 25, 0, 200, 6)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "HORDE DE ZOMBIES", "Ils sont lents. Ils ne font pas tres mal. Ils ne sont pas resistants. Mais ils nombreux, tres nombreux, vraiment tres nombreux ...", MONSTER_14_IMAGE_PATH, 25, 0, 200, 6)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "BEBE DRAGON", "Ooooooh, qu'il est mignon ! On aurait presque envie de lui faire des calins, ... enfin s'il ne crachait pas du feu sur toutes les personnes qui l'approchent...", MONSTER_15_IMAGE_PATH, 40, 10, 200, 7)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, false, "BEBE DRAGON", "Ooooooh, qu'il est mignon ! On aurait presque envie de lui faire des calins, ... enfin s'il ne crachait pas du feu sur toutes les personnes qui l'approchent...", MONSTER_15_IMAGE_PATH, 40, 10, 200, 7)));
    // 30 CARDS
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "PIEGE MECANIQUE", "Aie !! Il vaut mieux sortir de la en vitesse.",  TRAP_1_IMAGE_PATH, LIFE, 25)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "PIEGE MECANIQUE", "Aie !! Il vaut mieux sortir de la en vitesse.",  TRAP_1_IMAGE_PATH, LIFE, 25)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "PIEGE MECANIQUE", "Aie !! Il vaut mieux sortir de la en vitesse.",  TRAP_1_IMAGE_PATH, LIFE, 25)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "PIEGE MECANIQUE", "Aie !! Il vaut mieux sortir de la en vitesse.",  TRAP_1_IMAGE_PATH, LIFE, 25)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "PIEGE MECANIQUE", "Aie !! Il vaut mieux sortir de la en vitesse.",  TRAP_1_IMAGE_PATH, LIFE, 25)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "UN SLIME TOUT GLUANT", "Il commence a s'infiltrer entre les plaques de votre armure, reduisant votre mobilite",  TRAP_2_IMAGE_PATH, AGILITY, 4)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "UN SLIME TOUT GLUANT", "Il commence a s'infiltrer entre les plaques de votre armure, reduisant votre mobilite",  TRAP_2_IMAGE_PATH, AGILITY, 4)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "UN SLIME TOUT GLUANT", "Il commence a s'infiltrer entre les plaques de votre armure, reduisant votre mobilite",  TRAP_2_IMAGE_PATH, AGILITY, 4)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "UN SLIME TOUT GLUANT", "Il commence a s'infiltrer entre les plaques de votre armure, reduisant votre mobilite",  TRAP_2_IMAGE_PATH, AGILITY, 4)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "UN SLIME TOUT GLUANT", "Il commence a s'infiltrer entre les plaques de votre armure, reduisant votre mobilite",  TRAP_2_IMAGE_PATH, AGILITY, 4)));
   // 40 CARDS
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "PIEGE D'ACIDE", "Votre epee et le reste de votre equipement commence a fondre ...",  TRAP_3_IMAGE_PATH, ATTACK, 4)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "PIEGE D'ACIDE", "Votre epee et le reste de votre equipement commence a fondre ...",  TRAP_3_IMAGE_PATH, ATTACK, 4)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "PIEGE D'ACIDE", "Votre epee et le reste de votre equipement commence a fondre ...",  TRAP_3_IMAGE_PATH, ATTACK, 4)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "PIEGE D'ACIDE", "Votre epee et le reste de votre equipement commence a fondre ...",  TRAP_3_IMAGE_PATH, ATTACK, 4)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "PIEGE D'ACIDE", "Votre epee et le reste de votre equipement commence a fondre ...",  TRAP_3_IMAGE_PATH, ATTACK, 4)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "PIEGE DE FLAMMES", "Des flammes commencent a sortir du sol, et transforment vos belles bottes en un petit tas de cendres.",  TRAP_4_IMAGE_PATH, DEFENSE, 4)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "PIEGE DE FLAMMES", "Des flammes commencent a sortir du sol, et transforment vos belles bottes en un petit tas de cendres.",  TRAP_4_IMAGE_PATH, DEFENSE, 4)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "PIEGE DE FLAMMES", "Des flammes commencent a sortir du sol, et transforment vos belles bottes en un petit tas de cendres.",  TRAP_4_IMAGE_PATH, DEFENSE, 4)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "PIEGE DE FLAMMES", "Des flammes commencent a sortir du sol, et transforment vos belles bottes en un petit tas de cendres.",  TRAP_4_IMAGE_PATH, DEFENSE, 4)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "PIEGE DE FLAMMES", "Des flammes commencent a sortir du sol, et transforment vos belles bottes en un petit tas de cendres.",  TRAP_4_IMAGE_PATH, DEFENSE, 4)));
    // 50 CARDS
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "LE PLAFOND S'EFFONDRE !", "Vous recevez un gros caillou sur la tete, vous avez de la chance d'avoir la tete dure.",  TRAP_5_IMAGE_PATH, LIFE, 10)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "LE PLAFOND S'EFFONDRE !", "Vous recevez un gros caillou sur la tete, vous avez de la chance d'avoir la tete dure.",  TRAP_5_IMAGE_PATH, LIFE, 10)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "LE PLAFOND S'EFFONDRE !", "Vous recevez un gros caillou sur la tete, vous avez de la chance d'avoir la tete dure.",  TRAP_5_IMAGE_PATH, LIFE, 10)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "LE PLAFOND S'EFFONDRE !", "Vous recevez un gros caillou sur la tete, vous avez de la chance d'avoir la tete dure.",  TRAP_5_IMAGE_PATH, LIFE, 10)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "FLECHES MORTELLES", "Des fleches sortent d'un trou dans le mur et vous en recevez une dans le genou.", TRAP_6_IMAGE_PATH, AGILITY, 10)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "FLECHES MORTELLES", "Des fleches sortent d'un trou dans le mur et vous en recevez une dans le genou.", TRAP_6_IMAGE_PATH, AGILITY, 10)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "FLECHES MORTELLES", "Des fleches sortent d'un trou dans le mur et vous en recevez une dans le genou.", TRAP_6_IMAGE_PATH, AGILITY, 10)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "FUMEE MALEFIQUE", "Un nuage de fumee multicolore vous entoure. Quand il se dissipe, vous vous rendez compte qu'il vous a pris toute votre armure.", TRAP_7_IMAGE_PATH, DEFENSE, 10)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "FUMEE MALEFIQUE", "Un nuage de fumee multicolore vous entoure. Quand il se dissipe, vous vous rendez compte qu'il vous a pris toute votre armure.", TRAP_7_IMAGE_PATH, DEFENSE, 10)));
    _allRooms.push_back(unique_ptr<Room>(new Trap(TRAP, "FUMEE MALEFIQUE", "Un nuage de fumee multicolore vous entoure. Quand il se dissipe, vous vous rendez compte qu'il vous a pris toute votre armure.", TRAP_7_IMAGE_PATH, DEFENSE, 10)));
    // 60 CARDS
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "EPEE EN ARGENT", "Vous vous sentez pret a affronter les loups-garous a present !", TREASURE_1_IMAGE_PATH, ATTACK, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "EPEE EN ARGENT", "Vous vous sentez pret a affronter les loups-garous a present !", TREASURE_1_IMAGE_PATH, ATTACK, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "EPEE EN ARGENT", "Vous vous sentez pret a affronter les loups-garous a present !", TREASURE_1_IMAGE_PATH, ATTACK, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "EPEE EN ARGENT", "Vous vous sentez pret a affronter les loups-garous a present !", TREASURE_1_IMAGE_PATH, ATTACK, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "EPEE EN ARGENT", "Vous vous sentez pret a affronter les loups-garous a present !", TREASURE_1_IMAGE_PATH, ATTACK, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "CAPE DE VOLEUR", "Pas sur qu'elle soit tres utile, mais en tout cas elle est jolie ! !", TREASURE_2_IMAGE_PATH, AGILITY, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "CAPE DE VOLEUR", "Pas sur qu'elle soit tres utile, mais en tout cas elle est jolie ! !", TREASURE_2_IMAGE_PATH, AGILITY, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "CAPE DE VOLEUR", "Pas sur qu'elle soit tres utile, mais en tout cas elle est jolie ! !", TREASURE_2_IMAGE_PATH, AGILITY, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "CAPE DE VOLEUR", "Pas sur qu'elle soit tres utile, mais en tout cas elle est jolie ! !", TREASURE_2_IMAGE_PATH, AGILITY, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "CAPE DE VOLEUR", "Pas sur qu'elle soit tres utile, mais en tout cas elle est jolie ! !", TREASURE_2_IMAGE_PATH, AGILITY, 3)));
    // 70 CARDS
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "CASQUE EN OR", "Quoi, l'or n'est pas plus solide que le fer ? Heureusement qu'on est que dans un jeu video alors !", TREASURE_3_IMAGE_PATH, DEFENSE, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "CASQUE EN OR", "Quoi, l'or n'est pas plus solide que le fer ? Heureusement qu'on est que dans un jeu video alors !", TREASURE_3_IMAGE_PATH, DEFENSE, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "CASQUE EN OR", "Quoi, l'or n'est pas plus solide que le fer ? Heureusement qu'on est que dans un jeu video alors !", TREASURE_3_IMAGE_PATH, DEFENSE, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "CASQUE EN OR", "Quoi, l'or n'est pas plus solide que le fer ? Heureusement qu'on est que dans un jeu video alors !", TREASURE_3_IMAGE_PATH, DEFENSE, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "CASQUE EN OR", "Quoi, l'or n'est pas plus solide que le fer ? Heureusement qu'on est que dans un jeu video alors !", TREASURE_3_IMAGE_PATH, DEFENSE, 3)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "POULET ROTI", "Apres un aussi bon repas, vous vous sentez d'attaque pour tout detruire sur votre chemin !", TREASURE_4_IMAGE_PATH, LIFE, 30)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "POULET ROTI", "Apres un aussi bon repas, vous vous sentez d'attaque pour tout detruire sur votre chemin !", TREASURE_4_IMAGE_PATH, LIFE, 30)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "POULET ROTI", "Apres un aussi bon repas, vous vous sentez d'attaque pour tout detruire sur votre chemin !", TREASURE_4_IMAGE_PATH, LIFE, 30)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "POULET ROTI", "Apres un aussi bon repas, vous vous sentez d'attaque pour tout detruire sur votre chemin !", TREASURE_4_IMAGE_PATH, LIFE, 30)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "POULET ROTI", "Apres un aussi bon repas, vous vous sentez d'attaque pour tout detruire sur votre chemin !", TREASURE_4_IMAGE_PATH, LIFE, 30)));
    // 80 CARDS
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "POTION DE REGENERATION", "Glou, glou, glou ! Vous n'en laissez pas une goutte. C'est pas bon, mais vous regagnez des points de vie !", TREASURE_5_IMAGE_PATH, LIFE, 80)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "POTION DE REGENERATION", "Glou, glou, glou ! Vous n'en laissez pas une goutte. C'est pas bon, mais vous regagnez des points de vie !", TREASURE_5_IMAGE_PATH, LIFE, 80)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "POTION DE REGENERATION", "Glou, glou, glou ! Vous n'en laissez pas une goutte. C'est pas bon, mais vous regagnez des points de vie !", TREASURE_5_IMAGE_PATH, LIFE, 80)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "POTION DE REGENERATION", "Glou, glou, glou ! Vous n'en laissez pas une goutte. C'est pas bon, mais vous regagnez des points de vie !", TREASURE_5_IMAGE_PATH, LIFE, 80)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "SABRE LASER", "Objet plus ou moins magique provenant d'une galaxie lointaine, tres lointaine, ...", TREASURE_6_IMAGE_PATH, ATTACK, 7)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "SABRE LASER", "Objet plus ou moins magique provenant d'une galaxie lointaine, tres lointaine, ...", TREASURE_6_IMAGE_PATH, ATTACK, 7)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "SABRE LASER", "Objet plus ou moins magique provenant d'une galaxie lointaine, tres lointaine, ...", TREASURE_6_IMAGE_PATH, ATTACK, 7)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "BOUCLIER EN VIBRANIUM", "Il semble etre extremement resistant mais vous vous demandez qui a bien pu le peindre ainsi ...", TREASURE_7_IMAGE_PATH, AGILITY, 7)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "BOUCLIER EN VIBRANIUM", "Il semble etre extremement resistant mais vous vous demandez qui a bien pu le peindre ainsi ...", TREASURE_7_IMAGE_PATH, AGILITY, 7)));
    _allRooms.push_back(unique_ptr<Room>(new Treasure(TREASURE, "BOUCLIER EN VIBRANIUM", "Il semble etre extremement resistant mais vous vous demandez qui a bien pu le peindre ainsi ...", TREASURE_7_IMAGE_PATH, AGILITY, 7)));
    // 90 CARDS
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, true, "BOSS DU DONJON :\nDRAGON DE GLACE", "Dragon de glace qui crache du feu. La legende raconte qu'il viendrait d'un pays lointain a l'Ouest ...", BOSS_1_IMAGE_PATH, 50, 20, 300, 100)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, true, "BOSS DU DONJON :\nDRAGON DE GLACE", "Dragon de glace qui crache du feu. La legende raconte qu'il viendrait d'un pays lointain a l'Ouest ...", BOSS_1_IMAGE_PATH, 50, 20, 300, 100)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, true, "BOSS DU DONJON :\nCHEF ORC", "Il s'agit de l'orc alpha. Il n'aime visiblement pas du tout qu'on le derange pendant sa sieste ...", BOSS_2_IMAGE_PATH, 60, 5, 300, 100)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, true, "BOSS DU DONJON :\nCHEF ORC", "Il s'agit de l'orc alpha. Il n'aime visiblement pas du tout qu'on le derange pendant sa sieste ...", BOSS_2_IMAGE_PATH, 60, 5, 300, 100)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, true, "BOSS DU DONJON :\nDRACULA", "Le roi des vampires en chair et en os ... et en dents. Peut-etre que bruler son ame soeur n'etait pas la meilleure chose a faire avant de partir ... ", BOSS_3_IMAGE_PATH, 100, 5, 200, 100)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, true, "BOSS DU DONJON :\nDRACULA", "Le roi des vampires en chair et en os ... et en dents. Peut-etre que bruler son ame soeur n'etait pas la meilleure chose a faire avant de partir ... ", BOSS_3_IMAGE_PATH, 100, 5, 200, 100)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, true, "BOSS DU DONJON :\nGROSSE BESTIOLE", "Vous ne savez pas vraiment ce que c'est mais c'est sacrement moche alors il vaudrait mieux s'en debarrasser rapidement.", BOSS_4_IMAGE_PATH, 45, 25, 200, 100)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, true, "BOSS DU DONJON :\nGROSSE BESTIOLE", "Vous ne savez pas vraiment ce que c'est mais c'est sacrement moche alors il vaudrait mieux s'en debarrasser rapidement.", BOSS_4_IMAGE_PATH, 45, 25, 200, 100)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, true, "BOSS DU DONJON :\nCERBERE", "J'espere que vous avez pris votre flute. Non ? Bon, je pense qu'il faudra se contenter de votre bonne vieille epee...", BOSS_5_IMAGE_PATH, 50, 10, 400, 100)));
    _allRooms.push_back(unique_ptr<Room>(new Monster(MONSTER, true, "BOSS DU DONJON :\nCERBERE", "J'espere que vous avez pris votre flute. Non ? Bon, je pense qu'il faudra se contenter de votre bonne vieille epee...", BOSS_5_IMAGE_PATH, 50, 10, 400, 100)));
    // 100 CARDS
}

void Dungeon::generate()
{
    int randPosition;
    int nbInGameCards = NB_CARDS_INGAME;
    random_device r;
    default_random_engine randomEngine(r());
    uniform_int_distribution<int> uniformPositionDistribution(0, DISTANCE);

    while (nbInGameCards > 0)
    {
        randPosition = uniformPositionDistribution(randomEngine);

        while (nbInGameCards > 0 && randPosition < NB_CARDS && !_allRooms[randPosition]->inDeck())
        {
            _allRooms[randPosition]->setInDeck(true);
            _playedDeck.push_back(unique_ptr<Card>(new Card(_allRooms[randPosition].get(),
                                                            (NB_CARDS_INGAME - nbInGameCards) % CARDS_PER_LINE,
                                                            (NB_CARDS_INGAME - nbInGameCards) / CARDS_PER_LINE)));
            randPosition += DISTANCE;
            nbInGameCards --;
        }
    }
}

void Dungeon::regenerate()
{
    int randPosition;
    int nbInGameCards = NB_CARDS_INGAME;
    random_device r;
    default_random_engine randomEngine(r());
    uniform_int_distribution<int> uniformPositionDistribution(0, DISTANCE);

    while (nbInGameCards > 0)
    {
        randPosition = uniformPositionDistribution(randomEngine);

        while (nbInGameCards > 0 && randPosition < NB_CARDS && !_allRooms[randPosition]->inDeck())
        {
            _allRooms[randPosition]->setInDeck(true);

            _playedDeck[NB_CARDS_INGAME - nbInGameCards].reset(new Card(_allRooms[randPosition].get(),
                                                                        (NB_CARDS_INGAME - nbInGameCards) % CARDS_PER_LINE,
                                                                        (NB_CARDS_INGAME - nbInGameCards) / CARDS_PER_LINE));

            randPosition += DISTANCE;
            nbInGameCards --;
        }
    }
}

void Dungeon::init()
{
    for (int i = 0; i < NB_CARDS_INGAME; i++)
    {
        _playedDeck[i]->init();
    }
}

void Dungeon::handleEvent(SDL_Event * event)
{
    if (_activated)
    {
        if (event->type == SDL_MOUSEBUTTONDOWN)
        {
            // Get mouse position
            int x, y;
            x = event->button.x;
            y = event->button.y;

            Card * foundCard = findCard(x, y);
            if (foundCard != nullptr)
            {
                _lastVisitedCard = foundCard;
                _activated = false;
                foundCard->handleEvent(event);
            }
        }
    }

    else if (_lastVisitedCard != nullptr)
    {
        if (_lastVisitedCard->getRoom()->getBigCard()->displayed())
        {
            _lastVisitedCard->getRoom()->getBigCard()->handleEvent(event);
        }
    }
}

Card * Dungeon::findCard(int positionX, int positionY)
{
    for (auto &card : _playedDeck)
    {
        if (positionX >= card->getX() && positionX <= card->getX() + CARD_WIDTH && positionY >= card->getY()
            && positionY <= card->getY() + CARD_HEIGHT)
        {
            return card.get();
        }
    }
    return nullptr;
}

void Dungeon::update()
{
    for (int i = 0; i < NB_CARDS_INGAME; i++)
    {
        _playedDeck[i]->update();
        if (_playedDeck[i]->updatePlayer())
        {
            _playedDeck[i]->setUpdate(false);
            auto * playState = (PlayState *) GameStateManager::get().getCurrentGameState();
            playState->updateCurrentPlayer(_playedDeck[i]->getRoom(),
                                           _playedDeck[i]->getRoom()->getBigCard()->accept());
            _playedDeck[i]->getRoom()->getBigCard()->setAccept(false);
            _playedDeck[i]->getRoom()->getBigCard()->setRefuse(false);

            _returnedCardsCount ++;
            if(_returnedCardsCount == NB_CARDS_INGAME)
            {
                cleanup();
                regenerate();
                init();
                _returnedCardsCount = 0;
            }
        }
    }
}

void Dungeon::render()
{
    bool noBigCard = true;
    for (int i = 0; i < NB_CARDS_INGAME; i++)
    {
        _playedDeck[i]->render();
        if (_playedDeck[i]->getRoom()->getBigCard()->displayed())
        {
            noBigCard = false;
        }
    }
    if (noBigCard)
    {
        _activated = true;
    }
}

void Dungeon::cleanup()
{
    for (int i = 0; i < NB_CARDS_INGAME; i++)
    {
        _playedDeck[i]->cleanup();
    }
}