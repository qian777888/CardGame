#ifndef CARD_VIEW_H
#define CARD_VIEW_H

#include "cocos2d.h"
#include "CardResConfig.h"

class CardView : public cocos2d::Node {
public:
    static CardView* create(CardFaceType faceType, CardSuitType suitType);

    void moveTo(const cocos2d::Vec2& target, float duration = 0.5f);

    inline int GetId()const { return _id; }
private:
    int _id;
    cocos2d::Sprite* backgroundSprite;
    cocos2d::Sprite* smallPointSprite;
    cocos2d::Sprite* largePointSprite;
    cocos2d::Sprite* suitSprite;

    bool init(CardFaceType faceType, CardSuitType suitType);
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    void initCardResources(CardFaceType faceType, CardSuitType suitType);
};

#endif     