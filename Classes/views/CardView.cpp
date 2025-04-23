#include "CardView.h"
#include "cocos2d.h"

USING_NS_CC;

CardView* CardView::create(CardFaceType faceType, CardSuitType suitType) {
    CardView* pRet = new(std::nothrow) CardView();
    if (pRet && pRet->init(faceType, suitType)) {
        pRet->autorelease();
        return pRet;
    }
    else {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

bool CardView::init(CardFaceType faceType, CardSuitType suitType) {
    if (!Node::init()) {
        return false;
    }

    initCardResources(faceType, suitType);

    // 设置 CardView 的大小为背景精灵的大小
    if (backgroundSprite) {
        this->setContentSize(backgroundSprite->getContentSize());
    }

    // 注册触摸事件监听器
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);

    touchListener->onTouchBegan = CC_CALLBACK_2(CardView::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(CardView::onTouchEnded, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}

void CardView::initCardResources(CardFaceType faceType, CardSuitType suitType) {
    auto& config = CardResConfig::getInstance();

    // 获取背景牌资源路径
    std::string backgroundPath = config.getBackgroundPath();
    // 获取小点数资源路径
    std::string smallPointPath = config.getSmallPointPath(faceType, suitType);
    // 获取花色资源路径
    std::string suitPath = config.getSuitPath(suitType);
    // 获取大点数资源路径
    std::string largePointPath = config.getLargePointPath(faceType, suitType);

    // 创建背景牌
    backgroundSprite = Sprite::create(backgroundPath);
    if (backgroundSprite) {
        this->addChild(backgroundSprite);
        backgroundSprite->setPosition(Vec2(0, 0));

        auto backgroundSize = backgroundSprite->getContentSize();

        // 计算上 1/5 区域的高度
        float topFifthHeight = backgroundSize.height / 5;

        // 创建小点数
        smallPointSprite = Sprite::create(smallPointPath);
        if (smallPointSprite) {
            this->addChild(smallPointSprite);
            float smallPointX = -backgroundSize.width / 4;
            float smallPointY = backgroundSize.height / 2 - topFifthHeight / 2;
            smallPointSprite->setPosition(Vec2(smallPointX, smallPointY));
        }

        // 创建花色
        suitSprite = Sprite::create(suitPath);
        if (suitSprite) {
            this->addChild(suitSprite);
            float suitX = backgroundSize.width / 4;
            float suitY = backgroundSize.height / 2 - topFifthHeight / 2;
            suitSprite->setPosition(Vec2(suitX, suitY));
        }

        // 创建大点数
        largePointSprite = Sprite::create(largePointPath);
        if (largePointSprite) {
            this->addChild(largePointSprite);
            float largePointY = -backgroundSize.height / 10;
            largePointSprite->setPosition(Vec2(0, largePointY));
        }
    }
}

bool CardView::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {
    Vec2 locationInNode = this->convertToNodeSpace(touch->getLocation());
    Size size = this->getContentSize();
    Vec2 origin = Vec2(-size.width * 0.5, -size.height * 0.5);
    Rect rect = Rect(origin.x, origin.y, size.width, size.height);

    if (rect.containsPoint(locationInNode)) {
        // 点击时放大
        this->setScale(1.2f);
        return true;
    }
    return false;
}

void CardView::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) {
    Vec2 locationInNode = this->convertToNodeSpace(touch->getLocation());
    Size size = this->getContentSize();
    Vec2 origin = Vec2(-size.width * 0.5, -size.height * 0.5);
    Rect rect = Rect(origin.x, origin.y, size.width, size.height);

    if (rect.containsPoint(locationInNode)) {
        // 如果结束时在卡牌范围内，在屏幕上显示 Hello World
        auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
        if (label) {
            auto visibleSize = Director::getInstance()->getVisibleSize();
            label->setPosition(visibleSize.width / 2, visibleSize.height / 2);
            this->getParent()->addChild(label);
        }
    }
    // 无论触摸结束位置是否在卡牌范围内，都恢复卡牌大小
    this->setScale(1.0f);
}
void CardView::moveTo(const cocos2d::Vec2& target, float duration) {
    auto moveAction = cocos2d::MoveTo::create(duration, target);
    this->runAction(moveAction);
}