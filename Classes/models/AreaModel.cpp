#include "AreaModel.h"

AreaModel::AreaModel(const cocos2d::Vec2& center, float xLength, float yLength)
    : _center(center), _xLength(xLength), _yLength(yLength) {}

bool AreaModel::isPointInArea(const cocos2d::Vec2& point) const {
    float halfXLength = _xLength / 2.0f;
    float halfYLength = _yLength / 2.0f;

    float minX = _center.x - halfXLength;
    float maxX = _center.x + halfXLength;
    float minY = _center.y - halfYLength;
    float maxY = _center.y + halfYLength;

    return point.x >= minX && point.x <= maxX && point.y >= minY && point.y <= maxY;
}