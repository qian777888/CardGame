#ifndef LEVEL_CONFIG_LOADER_H
#define LEVEL_CONFIG_LOADER_H

#include <string>
#include "LevelConfig.h"
#include "cocos2d.h"

class LevelConfigLoader {
public:
    // 根据关卡编号加载关卡配置的静态方法
    static LevelInfo loadLevelConfig(int levelNumber);
};

#endif    
