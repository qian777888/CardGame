#ifndef LEVEL_CONFIG_LOADER_H
#define LEVEL_CONFIG_LOADER_H

#include <string>
#include "LevelConfig.h"
#include "cocos2d.h"

class LevelConfigLoader {
public:
    // ���ݹؿ���ż��عؿ����õľ�̬����
    static LevelInfo loadLevelConfig(int levelNumber);
};

#endif    
