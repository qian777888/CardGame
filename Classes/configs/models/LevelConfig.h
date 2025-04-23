#ifndef LEVEL_CONFIG_H
#define LEVEL_CONFIG_H

#include <string>
#include <vector>
#include "cocos2d.h"
#include <unordered_map>
// 卡牌结构体
struct Card {
    int cardFace;
    int cardSuit;
    cocos2d::Vec2 position;
};

// 关卡配置结构体
struct LevelInfo {
    std::vector<Card> playfield;
    std::vector<Card> stack;
    Card HardCard;
};

class LevelConfig {
public:
    // 获取单例实例
    static LevelConfig& getInstance() {
        static LevelConfig instance;
        return instance;
    }
    std::string& getLevelPath(int levelnum) { return _levelPaths[levelnum]; }
private:
    // 禁止拷贝构造和赋值运算符
    LevelConfig(const LevelConfig&) = delete;
    LevelConfig& operator=(const LevelConfig&) = delete;
    
    // 私有构造函数
    LevelConfig() {
        // 添加自定义资源路径
        auto fileUtils = cocos2d::FileUtils::getInstance();

        // 添加优先级更高的路径（优先搜索）
        fileUtils->addSearchPath("level/");
        _levelPaths.push_back("");
    }
    std::vector<std::string>_levelPaths;
};

#endif    