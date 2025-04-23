#include "CardModel.h"
#include "json/writer.h"
#include "json/stringbuffer.h"

CardModel::CardModel(int cardId, CardFaceType face, CardSuitType suit, bool isRevealed, cocos2d::Vec2 position)
    : _cardId(cardId), _face(face), _suit(suit), _isRevealed(isRevealed), _position(position) {}

rapidjson::Value CardModel::serialize(rapidjson::Document::AllocatorType& allocator) const {
    rapidjson::Value cardJson(rapidjson::kObjectType);
    cardJson.AddMember("cardId", _cardId, allocator);
    cardJson.AddMember("face", static_cast<int>(_face), allocator);
    cardJson.AddMember("suit", static_cast<int>(_suit), allocator);
    cardJson.AddMember("isRevealed", _isRevealed, allocator);
    rapidjson::Value positionJson(rapidjson::kObjectType);
    positionJson.AddMember("x", _position.x, allocator);
    positionJson.AddMember("y", _position.y, allocator);
    cardJson.AddMember("position", positionJson, allocator);
    return cardJson;
}

CardModel CardModel::deserialize(const rapidjson::Value& json) {
    int cardId = json["cardId"].GetInt();
    CardFaceType face = static_cast<CardFaceType>(json["face"].GetInt());
    CardSuitType suit = static_cast<CardSuitType>(json["suit"].GetInt());
    bool isRevealed = json["isRevealed"].GetBool();
    cocos2d::Vec2 position(json["position"]["x"].GetFloat(), json["position"]["y"].GetFloat());
    return CardModel(cardId, face, suit, isRevealed, position);
}