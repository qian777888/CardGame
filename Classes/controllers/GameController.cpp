#include "GameController.h"
#include "LevelConfigLoader.h"
#include "GameModelFromLevelGenerator.h"
#include "PlayFieldController.h"
#include "StackController.h"
#include "UndoManager.h"

#include <iostream>

GameController::GameController() : _view(nullptr) {}

void GameController::startGame(int levelId) {
    // 1. ���� LevelConfigLoader::loadLevelConfig(levelId) ��ȡ LevelConfig
    LevelConfigLoader::loadLevelConfig(levelId);
    const LevelInfo* levelInfo=LevelConfig::getInstance().getLevelInfo(levelId);
    // 2. ʹ�� GameModelFromLevelGenerator::generateGameModel ���� GameModel
    _model = GameModelFromLevelGenerator::generateGameModel(config);

    // 3. ��ʼ�����ӿ�����
    PlayFieldController::init(_model, *_view);
    StackController::init(_model, *_view);
    UndoManager::init(_model, *_view);

    // 4. ���� GameView ����ӵ����ڵ�
    _view = GameView::create();
    if (_view) {
        // ����������һ�����ڵ� parentNode��ʵ��ʹ��ʱ��Ҫ�滻Ϊ��ȷ�ĸ��ڵ�
        cocos2d::Node* parentNode = cocos2d::Director::getInstance()->getRunningScene();
        parentNode->addChild(_view);
    }

    // 5. ��ʼ�����ӿ���������ͼ
    StackController::initView(*_view);
    PlayFieldController::initView(*_view);

    // 6. GameView ��ʼ�� UI�����ó�ʼ����
    if (_view) {
        _view->initUI(); // ���� GameView �� initUI �������ڳ�ʼ�� UI
    }

    // 7. �����볡����
    if (_view) {
        _view->playEntryAnimation(); // ���� GameView �� playEntryAnimation �������ڲ����볡����
    }
}