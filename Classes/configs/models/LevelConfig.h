#ifndef LEVEL_CONFIG_H
#define LEVEL_CONFIG_H

#include <string>
#include <vector>
#include "cocos2d.h"
#include <unordered_map>
// ���ƽṹ��
struct Card {
    int cardFace;
    int cardSuit;
    cocos2d::Vec2 position;
};

// �ؿ����ýṹ��
struct LevelInfo {
    std::vector<Card> playfield;
    std::vector<Card> stack;
    Card HardCard;
};

class LevelConfig {
public:
    // ��ȡ����ʵ��
    static LevelConfig& getInstance() {
        static LevelConfig instance;
        return instance;
    }
    std::string& getLevelPath(int levelnum) { return _levelPaths[levelnum]; }
private:
    // ��ֹ��������͸�ֵ�����
    LevelConfig(const LevelConfig&) = delete;
    LevelConfig& operator=(const LevelConfig&) = delete;
    
    // ˽�й��캯��
    LevelConfig() {
        // ����Զ�����Դ·��
        auto fileUtils = cocos2d::FileUtils::getInstance();

        // ������ȼ����ߵ�·��������������
        fileUtils->addSearchPath("level/");
        _levelPaths.push_back("");
    }
    std::vector<std::string>_levelPaths;
};

#endif    