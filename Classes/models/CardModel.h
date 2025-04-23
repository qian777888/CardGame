#ifndef CARD_MODEL_H
#define CARD_MODEL_H

#include "cocos2d.h"
#include "json/document.h"
#include <string>
#include"CardResConfig.h"


class CardModel {
public:
    CardModel(int cardId, CardFaceType face, CardSuitType suit, bool isRevealed = false, cocos2d::Vec2 position = cocos2d::Vec2::ZERO);

    // ��������������
    inline int getCardId() const { return _cardId; }
    inline CardFaceType getFace() const { return _face; }
    inline CardSuitType getSuit() const { return _suit; }
    inline bool isRevealed() const { return _isRevealed; }
    inline cocos2d::Vec2 getPosition() const { return _position; }

    // �����޸�������
    inline void setRevealed(bool revealed) { _isRevealed = revealed; }
    inline void setPosition(const cocos2d::Vec2& position) { _position = position; }

    rapidjson::Value serialize(rapidjson::Document::AllocatorType& allocator) const;
    static CardModel deserialize(const rapidjson::Value& json);

private:
    int _cardId;                // Ψһ��ʶ
    CardFaceType _face;         // ����ֵ
    CardSuitType _suit;         // ��ɫ
    bool _isRevealed;           // �Ƿ񷭿�
    cocos2d::Vec2 _position;    // �߼�����
};

#endif    