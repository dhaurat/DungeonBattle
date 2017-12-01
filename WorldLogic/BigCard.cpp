//
// Created on 24/11/2017.
//

#include "BigCard.h"
#include "../GUI/GUIConstants.h"

#define BIG_CARD_PATH "./res/BigCard.png"
#define REFUSE_BTN_PATH "./res/FleeBtn.png"

BigCard::BigCard(bool hasRefuseBtn, const char * acceptBtnPath, const char * entityImagePath, string topText,
                 const char * entityNameText,
                 const char * descriptionText) : _cardImage(BIG_CARD_PATH, BIG_CARD_MARGIN_SIDE,
                                                            BIG_CARD_MARGIN_TOP, BIG_CARD_WIDTH,
                                                            BIG_CARD_HEIGHT),

                                                 _acceptBtn(acceptBtnPath, BIG_CARD_MARGIN_SIDE
                                                                           + 40, BIG_CARD_MARGIN_TOP
                                                                     + BIG_CARD_HEIGHT - 100,
                                                            BUTTON_BIG_CARD_WIDTH, BUTTON_BIG_CARD_HEIGHT),

                                                 _refuseBtn(REFUSE_BTN_PATH, BIG_CARD_MARGIN_SIDE
                                                                             + 180, BIG_CARD_MARGIN_TOP
                                                                     + BIG_CARD_HEIGHT - 100,
                                                            BUTTON_BIG_CARD_WIDTH, BUTTON_BIG_CARD_HEIGHT),

                                                 _entityImage(entityImagePath, BIG_CARD_MARGIN_SIDE
                                                                               + ENTITY_IMAGE_MARGIN_SIDE,
                                                              BIG_CARD_MARGIN_TOP  +
                                                                      ENTITY_IMAGE_MARGIN_TOP, ENTITY_IMAGE_WIDTH,
                                                              ENTITY_IMAGE_HEIGHT),

                                                 _topTxt(TTF_OpenFont(FONT_PATH, 25), 0, 0, 0, topText.c_str(),
                                                         BIG_CARD_MARGIN_SIDE
                                                         + ENTITY_IMAGE_MARGIN_SIDE, BIG_CARD_MARGIN_TOP
                                                                                      + 30, BIG_CARD_WIDTH-70),

                                                 _entityNameTxt(TTF_OpenFont(FONT_PATH, 25), 0, 0, 0, entityNameText,
                                                                BIG_CARD_MARGIN_SIDE
                                                                + ENTITY_IMAGE_MARGIN_SIDE, BIG_CARD_MARGIN_TOP
                                                                         + ENTITY_IMAGE_MARGIN_TOP
                                                                                            + ENTITY_IMAGE_HEIGHT + 10, BIG_CARD_WIDTH-70),

                                                 _descriptionTxt(TTF_OpenFont(FONT_PATH, 20), 0, 0, 0, descriptionText,
                                                                 BIG_CARD_MARGIN_SIDE
                                                                 + ENTITY_IMAGE_MARGIN_SIDE, BIG_CARD_MARGIN_TOP
                                                                                              +
                                                                         ENTITY_IMAGE_MARGIN_TOP + ENTITY_IMAGE_HEIGHT
                                                                                             + 70, BIG_CARD_WIDTH-70)
{
    _hasRefuseBtn = hasRefuseBtn;
    _displayed = false;
    _accept = false;
    _refuse = false;
}

bool BigCard::hasRefuseBtn() const
{
    return _hasRefuseBtn;
}

bool BigCard::displayed() const
{
    return _displayed;
}

bool BigCard::accept() const
{
    return _accept;
}

bool BigCard::refuse() const
{
    return _refuse;
}

void BigCard::setAccept(bool accept)
{
    _accept = accept;
}

void BigCard::setRefuse(bool refuse)
{
    _refuse = refuse;
}

void BigCard::setDisplay(bool displayed)
{
    _displayed = displayed;
}

void BigCard::init()
{
    _cardImage.init();
    _acceptBtn.init();
    if (hasRefuseBtn())
    {
        _refuseBtn.init();
    }
    _entityImage.init();
}

void BigCard::handleEvent(SDL_Event * event)
{
    _acceptBtn.handleEvent(event);
    if (hasRefuseBtn())
    {
        _refuseBtn.handleEvent(event);
    }
    if (_acceptBtn.pressed())
    {
        setAccept(true);
        setDisplay(false);
        cleanup();
    }
    else if (_refuseBtn.pressed())
    {
        setRefuse(true);
        setDisplay(false);
        cleanup();
    }
}

void BigCard::render()
{
    _cardImage.render();
    _acceptBtn.render();
    if (hasRefuseBtn())
    {
        _refuseBtn.render();
    }
    _entityImage.render();
    _topTxt.render();
    _entityNameTxt.render();
    _descriptionTxt.render();
}

void BigCard::cleanup()
{
    _descriptionTxt.cleanup();
    _entityNameTxt.cleanup();
    _topTxt.cleanup();
    _entityImage.cleanup();
    if (hasRefuseBtn())
    {
        _refuseBtn.cleanup();
    }
    _acceptBtn.cleanup();
    _cardImage.cleanup();
}
