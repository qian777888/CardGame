#include "GameController.h"
#include "LevelConfigLoader.h"
#include "GameModelFromLevelGenerator.h"
#include "PlayFieldController.h"
#include "StackController.h"
#include "UndoManager.h"

#include <iostream>

GameController::GameController() : _view(nullptr) {}

void GameController::startGame(int levelId) {
    // 1. 调用 LevelConfigLoader::loadLevelConfig(levelId) 获取 LevelConfig
    LevelConfigLoader::loadLevelConfig(levelId);
    const LevelInfo* levelInfo=LevelConfig::getInstance().getLevelInfo(levelId);
    // 2. 使用 GameModelFromLevelGenerator::generateGameModel 生成 GameModel
    _model = GameModelFromLevelGenerator::generateGameModel(config);

    // 3. 初始化各子控制器
    PlayFieldController::init(_model, *_view);
    StackController::init(_model, *_view);
    UndoManager::init(_model, *_view);

    // 4. 创建 GameView 并添加到父节点
    _view = GameView::create();
    if (_view) {
        // 假设这里有一个父节点 parentNode，实际使用时需要替换为正确的父节点
        cocos2d::Node* parentNode = cocos2d::Director::getInstance()->getRunningScene();
        parentNode->addChild(_view);
    }

    // 5. 初始化各子控制器的视图
    StackController::initView(*_view);
    PlayFieldController::initView(*_view);

    // 6. GameView 初始化 UI，设置初始布局
    if (_view) {
        _view->initUI(); // 假设 GameView 有 initUI 方法用于初始化 UI
    }

    // 7. 播放入场动画
    if (_view) {
        _view->playEntryAnimation(); // 假设 GameView 有 playEntryAnimation 方法用于播放入场动画
    }
}