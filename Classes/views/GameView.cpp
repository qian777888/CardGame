#include "GameView.h"
#include "CardView.h"
#include "base/ccTypes.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
GameView* GameView::create() {
    GameView* pRet = new(std::nothrow) GameView();
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    }
    else {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

bool GameView::init() {
    if (!cocos2d::Layer::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // Ö÷ÅÆÇø³ß´ç£º1080*1500
    _mainAreaRect = cocos2d::Rect(0, 580, 1080, 1500);
    // ¶ÑÅÆÇø³ß´ç: 1080*580
    _pileAreaRect = cocos2d::Rect(0, 0, 1080, 580);

    // Ö÷ÅÆÇø
    auto mainCardArea = cocos2d::LayerColor::create(Color4B(100, 100, 255, 255), 1080, 1500);
    mainCardArea->setPosition(Vec2(origin.x, origin.y + 580));
    this->addChild(mainCardArea);

    // ¶ÑÅÆÇø
    auto pileCardArea = LayerColor::create(Color4B(255, 100, 100, 255), 1080, 580);
    pileCardArea->setPosition(Vec2(origin.x, origin.y));
    this->addChild(pileCardArea);

    return true;
}

void GameView::showMatchSuccessAnimation() {
    // ¼òµ¥Ê¾Àý£º¿¨ÅÆÉÁË¸¶¯»­
    for (auto& pair : _cardViewMap) {
        auto cardView = pair.second;
        auto fadeOut = cocos2d::FadeOut::create(0.2f);
        auto fadeIn = cocos2d::FadeIn::create(0.2f);
        auto sequence = cocos2d::Sequence::create(fadeOut, fadeIn, fadeOut, fadeIn, nullptr);
        cardView->runAction(sequence);
    }
}

CardView* GameView::findCardViewById(int cardId) {
    auto it = _cardViewMap.find(cardId);
    if (it != _cardViewMap.end()) {
        return it->second;
    }
    return nullptr;
}

void GameView::addCardView(CardView* cardView) {
    if (cardView) {
        _cardViewMap[cardView->GetId()] = cardView;
        this->addChild(cardView);
    }
}