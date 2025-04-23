#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include <vector>
#include <stack>
#include "CardModel.h"
#include "json/document.h"

class GameModel {
public:
    GameModel();

    // ��������������
    inline const std::vector<CardModel>& getMainAreaCards() const { return _mainAreaCards; }
    inline const CardModel& getCurrentBottomCard() const { return _currentBottomCard; }
    inline const std::stack<CardModel>& getReservePile() const { return _reservePile; }

    // �����޸�������
    inline void addCardToMainArea(const CardModel& card) { _mainAreaCards.push_back(card); }
    inline void setCurrentBottomCard(const CardModel& card) { _currentBottomCard = card; }
    inline void pushToReservePile(const CardModel& card) { _reservePile.push(card); }

    CardModel popFromReservePile();

    rapidjson::Value serialize(rapidjson::Document::AllocatorType& allocator) const;
    static GameModel deserialize(const rapidjson::Value& json);

private:
    std::vector<CardModel> _mainAreaCards;  // ���ƶ�
    CardModel _currentBottomCard;           // ��ǰ����
    std::stack<CardModel> _reservePile;     // �����ƶ�
};

#endif    