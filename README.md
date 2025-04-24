扑克牌游戏项目 README\
一、项目概述\
本项目是一个基于 Cocos2d-x 的扑克牌游戏，采用 模型 - 视图 - 控制器（MVC）架构 设计。实现了扑克牌布局管理、卡牌点击与移动等交互操作、匹配判断以及撤销操作等功能，通过架构分层有效提升代码的可维护性与扩展性。\
二、项目结构\
plaintext\
项目根目录\
├── Classes\
│   ├── models          // 游戏模型相关类\
│   │   ├── CardModel.h  // 扑克牌模型类\
│   │   ├── GameModel.h  // 游戏整体模型类\
│   │   └── ...\
│   ├── controllers     // 游戏控制器相关类\
│   │   ├── GameController.h  // 游戏主控制器类\
│   │   ├── PlayFieldController.h  // 主牌区域控制器类\
│   │   └── ...\
│   ├── views           // 游戏视图相关类\
│   │   ├── CardView.h  // 扑克牌视图类\
│   │   ├── GameView.h  // 游戏整体视图类\
│   │   └── ...\
│   ├── service         // 服务类\
│   │   ├── CardIntersection.h  // 卡牌相交判断类\
│   │   ├── JudgeMatchService.h  // 卡牌匹配判断类\
│   │   └── ...\
│   └── manager         // 管理类\
│       └── UndoManager.h  // 管理撤销操作的类\
├── Resources           // 游戏资源文件（图片、配置文件等）\
├── README.md           // 项目说明文档\
└── ...\
三、核心类说明\
（一）模型类（models 目录）\
CardModel：\
单张扑克牌模型，存储卡牌 ID、点数、花色、翻开状态、位置 等信息，支持序列化与反序列化，便于数据存储和传输。\
GameModel：\
游戏整体模型，管理 主牌堆、当前底牌、备用牌堆 数据，提供数据访问、修改方法及序列化 / 反序列化功能，实现游戏状态管理。\
（二）控制器类（controllers 目录）\
GameController：\
游戏主控制器，负责游戏初始化、启动流程，协调各子控制器与管理器，保障游戏整体运行\
PlayFieldController：\
控制主牌区域逻辑，处理卡牌点击事件与布局更新，实现主牌区域交互逻辑。\
StackController：\
管理栈区域逻辑，处理栈内卡牌点击和移动操作，实现栈区域交互功能。\
UndoController：\
处理撤销按钮交互，更新按钮状态并调用撤销管理器执行撤销操作，实现游戏撤销功能。\
（三）视图类（views 目录）\
CardView：\
继承自 cocos2d::Node，实现扑克牌图形展示、移动动画和点击交互，提供可视化操作界面。\
GameView：\
游戏整体视图，管理所有卡牌视图显示，提供卡牌查找和添加功能，负责界面整体呈现。\
PlayFieldView：\
主牌区域视图，处理区域内卡牌点击回调，实现主牌区域交互响应。\
StackView：\
栈区域视图，负责栈内卡牌显示与点击事件处理，展示栈区域卡牌状态。\
UndoButtonView：\
创建撤销按钮，根据撤销状态实时更新按钮可用状态，提示操作可行性。\
（四）服务类（service 目录）\
CardIntersectionService：\
判断两张扑克牌是否相交，为卡牌布局和交互提供逻辑支持。\
JudgeMatchService：\
判断扑克牌点数是否匹配，实现游戏核心匹配逻辑。\
（五）管理类（manager 目录）\
UndoManager：\
通过栈结构记录操作信息，实现游戏撤销功能，允许用户回滚操作。\
四、使用说明\
1.使用 Visual Studio 2022 打开 proj.win32 目录下的工程。\
2.proj.win32/Release.win32 为项目 release 版本，可直接运行游戏。\
3.目前仅在 Windows 平台测试 \

