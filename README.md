扑克牌游戏项目 README
一、项目概述
本项目是一个基于 Cocos2d-x 的扑克牌游戏，主要实现了扑克牌的布局管理、交互操作（如卡牌点击、移动）、匹配判断、撤销操作等功能。通过模型 - 视图 - 控制器（MVC）架构，将游戏数据、界面展示和逻辑控制分离，提高了代码的可维护性和扩展性。
二、项目结构
plaintext
项目根目录
├── Classes
│   ├── models          // 游戏模型相关类
│   │   ├── CardModel.h  // 扑克牌模型类
│   │   ├── GameModel.h  // 游戏整体模型类
│   │   └── ...
│   ├── controllers     // 游戏控制器相关类
│   │   ├── GameController.h  // 游戏主控制器类
│   │   ├── PlayFieldController.h  // 主牌区域控制器类
│   │   └── ...
│   ├── views           // 游戏视图相关类
│   │   ├── CardView.h  // 扑克牌视图类
│   │   ├── GameView.h  // 游戏整体视图类
│   │   └── ...
│   └── service           // 服务类
│       ├── CardIntersection.h  // 卡牌相交判断类
│       ├── JudgeMatchService.h  // 卡牌匹配判断类
│       └── ...
├── Resources           // 游戏资源文件（图片、配置文件等）
├── README.md           // 项目说明文档
└── ...
三、核心类说明
1. 模型类（models 目录）
CardModel：表示单张扑克牌的模型，存储卡牌的 ID、点数、花色、是否翻开、位置等信息，支持序列化和反序列化。
GameModel：游戏的整体模型，管理主牌堆、当前底牌、备用牌堆等数据，提供数据访问和修改方法，以及序列化和反序列化功能。
2. 控制器类（controllers 目录）
GameController：游戏的主控制器，负责游戏的初始化、开始流程，协调其他子控制器和管理器。
PlayFieldController：控制游戏主牌区域的逻辑，处理卡牌点击事件和布局更新。
StackController：控制栈区域的逻辑，管理栈内卡牌的点击和移动操作。
UndoController：处理撤销按钮的交互逻辑，更新按钮状态并调用撤销管理器执行撤销操作。
3. 视图类（views 目录）
CardView：表示扑克牌的视图，继承自 cocos2d::Node，实现卡牌的图形展示、移动动画和点击交互。
GameView：游戏的整体视图，管理所有卡牌视图的显示，提供卡牌查找和添加功能。
PlayFieldView：主牌区域的视图，处理该区域内卡牌的点击回调。
StackView：栈区域的视图，负责栈内卡牌的显示和点击事件处理。
UndoButtonView：撤销按钮的视图，创建按钮并根据撤销状态更新按钮的可用状态。
4. 服务类（service 目录）
CardIntersectionService：判断两张扑克牌是否相交的工具类。
JudgeMatchService：判断两张扑克牌点数是否匹配的工具类。
5.管理类（manager目录）
UndoManager：管理撤销操作的类，通过栈记录操作信息，实现撤销功能。
四、使用说明
1.windows下vs2022打开proj.win32目录下的工程
2.proj.win32/Release.win32是release版本
3.其他平台没试过

