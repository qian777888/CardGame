#ifndef AREA_MODEL_H
#define AREA_MODEL_H

#include "cocos2d.h"

class AreaModel {
public:
    AreaModel(const cocos2d::Vec2& center, float xLength, float yLength);

    // 内联访问器方法
    inline const cocos2d::Vec2& getCenter() const { return _center; }
    inline float getXLength() const { return _xLength; }
    inline float getYLength() const { return _yLength; }

    bool isPointInArea(const cocos2d::Vec2& point) const;

private:
    cocos2d::Vec2 _center;
    float _xLength;
    float _yLength;
};

#endif    