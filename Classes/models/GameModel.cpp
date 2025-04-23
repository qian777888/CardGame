#include "GameModel.h"
#include "json/writer.h"
#include "json/stringbuffer.h"

GameModel::GameModel() : _currentBottomCard(0, CardFaceType::CFT_NONE, CardSuitType::CST_NONE) {}

CardModel GameModel::popFromReservePile() {
    if (_reservePile.empty()) {
        return CardModel(0, CardFaceType::CFT_NONE, CardSuitType::CST_NONE);
    }
    CardModel topCard = _reservePile.top();
    _reservePile.pop();
    return topCard;
}

rapidjson::Value GameModel::serialize(rapidjson::Document::AllocatorType& allocator) const {
    rapidjson::Value gameJson(rapidjson::kObjectType);

    rapidjson::Value mainAreaCardsJson(rapidjson::kArrayType);
    for (const auto& card : _mainAreaCards) {
        mainAreaCardsJson.PushBack(card.serialize(allocator), allocator);
    }
    gameJson.AddMember("mainAreaCards", mainAreaCardsJson, allocator);

    gameJson.AddMember("currentBottomCard", _currentBottomCard.serialize(allocator), allocator);

    rapidjson::Value reservePileJson(rapidjson::kArrayType);
    std::stack<CardModel> tempStack = _reservePile;
    while (!tempStack.empty()) {
        reservePileJson.PushBack(tempStack.top().serialize(allocator), allocator);
        tempStack.pop();
    }
    gameJson.AddMember("reservePile", reservePileJson, allocator);

    return gameJson;
}

GameModel GameModel::deserialize(const rapidjson::Value& json) {
    GameModel gameModel;

    const rapidjson::Value& mainAreaCardsJson = json["mainAreaCards"];
    for (rapidjson::SizeType i = 0; i < mainAreaCardsJson.Size(); ++i) {
        gameModel.addCardToMainArea(CardModel::deserialize(mainAreaCardsJson[i]));
    }

    gameModel.setCurrentBottomCard(CardModel::deserialize(json["currentBottomCard"]));

    const rapidjson::Value& reservePileJson = json["reservePile"];
    for (rapidjson::SizeType i = 0; i < reservePileJson.Size(); ++i) {
        gameModel.pushToReservePile(CardModel::deserialize(reservePileJson[i]));
    }

    return gameModel;
}