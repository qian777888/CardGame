#include "LevelConfigLoader.h"
#include "cocos2d.h"
#include "json/document.h"
#include "json/filereadstream.h"
#include <iostream>
#include <cstdio>

using namespace cocos2d;
using namespace rapidjson;

LevelInfo  LevelConfigLoader::loadLevelConfig(int levelNumber) {
    auto& levelConfig = LevelConfig::getInstance();
    const std::string& path = levelConfig.getLevelPath(levelNumber);
    auto fileUtils = FileUtils::getInstance();
    std::string fullPath = fileUtils->fullPathForFilename(path);
    if (!fileUtils->isFileExist(fullPath)) {
        std::cerr << "File not found: " << path << std::endl;
        return;
    }

    std::string content = fileUtils->getStringFromFile(fullPath);
    Document doc;
    doc.Parse(content.c_str());

    if (doc.HasParseError()) {
        std::cerr << "JSON parse error: " << doc.GetParseError() << std::endl;
        return;
    }

    std::vector<Card> playfield;
    std::vector<Card> stack;

    // 解析 Playfield
    if (doc.HasMember("Playfield") && doc["Playfield"].IsArray()) {
        const auto& playfieldArray = doc["Playfield"];
        for (SizeType i = 0; i < playfieldArray.Size(); ++i) {
            const auto& cardObj = playfieldArray[i];
            Card card;
            card.cardFace = cardObj["CardFace"].GetInt();
            card.cardSuit = cardObj["CardSuit"].GetInt();
            const auto& positionObj = cardObj["Position"];
            card.position.x = positionObj["x"].GetFloat();
            card.position.y = positionObj["y"].GetFloat();
            playfield.push_back(card);
        }
    }

    // 解析 Stack
    if (doc.HasMember("Stack") && doc["Stack"].IsArray()) {
        const auto& stackArray = doc["Stack"];
        for (SizeType i = 0; i < stackArray.Size(); ++i) {
            const auto& cardObj = stackArray[i];
            Card card;
            card.cardFace = cardObj["CardFace"].GetInt();
            card.cardSuit = cardObj["CardSuit"].GetInt();
            const auto& positionObj = cardObj["Position"];
            card.position.x = positionObj["x"].GetFloat();
            card.position.y = positionObj["y"].GetFloat();
            stack.push_back(card);
        }
    }

    // 更新关卡配置信息
    return LevelInfo{ playfield ,stack };
}