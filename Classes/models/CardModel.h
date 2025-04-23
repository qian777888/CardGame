#ifndef CARD_MODEL_H
#define CARD_MODEL_H

#include "cocos2d.h"
#include "json/document.h"
#include <string>
#include"CardResConfig.h"


class CardModel {
public:
    CardModel(int cardId, CardFaceType face, CardSuitType suit, bool isRevealed = false, cocos2d::Vec2 position = cocos2d::Vec2::ZERO);

    // 内联访问器方法
    inline int getCardId() const { return _cardId; }
    inline CardFaceType getFace() const { return _face; }
    inline CardSuitType getSuit() const { return _suit; }
    inline bool isRevealed() const { return _isRevealed; }
    inline cocos2d::Vec2 getPosition() const { return _position; }

    // 内联修改器方法
    inline void setRevealed(bool revealed) { _isRevealed = revealed; }
    inline void setPosition(const cocos2d::Vec2& position) { _position = position; }

    rapidjson::Value serialize(rapidjson::Document::AllocatorType& allocator) const;
    static CardModel deserialize(const rapidjson::Value& json);

private:
    int _cardId;                // 唯一标识
    CardFaceType _face;         // 牌面值
    CardSuitType _suit;         // 花色
    bool _isRevealed;           // 是否翻开
    cocos2d::Vec2 _position;    // 逻辑坐标
};

#endif    