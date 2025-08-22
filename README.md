 TestCardGame 程序交付文档

 1. 项目概述

TestCardGame是一款基于cocos2d-x引擎开发的卡牌匹配游戏，运行于Windows平台。游戏采用MVC架构模式，提供多个关卡供玩家挑战，通过匹配相同卡牌完成游戏目标。

 1.1 游戏目标
玩家需要在游戏区域中找出并匹配具有相同面值和花色的卡牌，将它们放入匹配区域，完成所有卡牌的匹配即可通关。

 1.2 主要特点
- 基于cocos2d-x引擎的跨平台开发框架
- 清晰的MVC架构设计，便于维护和扩展
- 支持多关卡挑战，难度逐渐增加
- 实现撤销功能，提高游戏体验
- 支持从配置文件动态加载关卡数据

 2. 系统架构

 2.1 整体架构
项目采用典型的MVC架构设计，将游戏逻辑、数据模型和用户界面分离，便于维护和扩展。

```
┌───────────────────────────────────────────────────────┐
│                     视图层 (Views)                     │
│  ┌──────────────┐  ┌──────────────┐  ┌──────────────┐ │
│  │  GameView    │  │CardView      │  │LevelSelectView│ │
│  └──────────────┘  └──────────────┘  └──────────────┘ │
├───────────────────────────────────────────────────────┤
│                     控制层 (Controllers)               │
│  ┌──────────────┐  ┌──────────────┐  ┌──────────────┐ │
│  │GameController│  │StackController│  │LevelSelectCtrl│ │
│  └──────────────┘  └──────────────┘  └──────────────┘ │
├───────────────────────────────────────────────────────┤
│                     模型层 (Models)                    │
│  ┌──────────────┐  ┌──────────────┐  ┌──────────────┐ │
│  │ GameModel    │  │ CardModel    │  │CardStateModel│ │
│  └──────────────┘  └──────────────┘  └──────────────┘ │
└───────────────────────────────────────────────────────┘
```

 2.2 游戏流程图

```
开始游戏
  │
  ▼
加载AppDelegate
  │
  ▼
进入LevelSelectScene
  │
  ▼
选择关卡
  │
  ▼
加载LevelConfig.json
  │
  ▼
进入GameScene
  │
  ▼
初始化GameModel
  │
  ▼
渲染GameView
  │
  ├───────► 用户交互
  │          │
  │          ▼
  │       处理输入
  │          │
  │          ▼
  └───────► 更新模型
  │          │
  │          ▼
  └───────► 重新渲染
  │          │
  ▼          │
游戏结束 ◄───┘
```

 2.3 目录结构
项目源码按功能模块清晰分层，主要包括以下几个部分：

```
Classes/
├── controllers/     控制器类，处理游戏逻辑和用户交互
├── models/          数据模型类，管理游戏状态和数据
├── views/           视图类，负责渲染和显示
├── scenes/          场景类，管理游戏场景切换
├── configs/         配置加载器和模型定义
│   ├── loaders/     配置文件加载器
│   └── models/      配置相关的数据模型
├── managers/        管理器类，协调不同组件
├── services/        服务类，提供特定功能
└── utils/           工具类，提供通用功能
```

 3. 核心功能模块

 3.1 关卡系统
- 功能描述：管理游戏关卡的加载、显示和选择
- 关键文件：
  - `LevelConfigLoader.cpp` - 加载关卡配置文件
  - `LevelSelectScene.cpp` - 关卡选择场景
  - `LevelSelectController.cpp` - 关卡选择控制器
  - `LevelButtonView.cpp` - 关卡按钮视图
- 配置文件：`LevelConfig.json` - 定义各关卡的卡牌布局和初始状态
- 主要流程：
  1. 加载LevelConfig.json配置文件
  2. 解析关卡信息并创建关卡按钮
  3. 响应用户关卡选择操作
  4. 加载选定关卡的游戏数据

 3.2 游戏核心逻辑
- 功能描述：实现游戏的主要规则和逻辑
- 关键文件：
  - `GameController.cpp` - 游戏主控制器
  - `GameModel.cpp` - 游戏数据模型
  - `GameView.cpp` - 游戏主视图
- 关键组件：
  - GameController：游戏主控制器，协调各个子系统
  - GameModel：游戏数据模型，存储游戏状态和进度
  - GameView：游戏主视图，负责整体界面渲染
- 工作流程：
  1. 从配置文件加载关卡数据
  2. 初始化游戏区域和卡牌堆
  3. 处理用户输入和交互
  4. 更新游戏状态
  5. 渲染游戏画面
- 游戏区域：包含Playfield（游戏区域）和Stack（卡牌堆）两大部分

 3.3 卡牌系统
- 功能描述：管理卡牌的属性、状态和行为
- 关键文件：
  - `CardModel.cpp` - 卡牌数据模型
  - `CardStateModel.cpp` - 卡牌状态模型
  - `CardView.cpp` - 卡牌视图基类
  - `PlayfieldCardView.cpp` - 游戏区域卡牌视图
  - `StackCardView.cpp` - 卡牌堆视图
- 关键组件：
  - CardModel：定义卡牌的基本属性（面值、花色）
  - CardStateModel：管理卡牌的状态（翻开/覆盖、选中/未选中）
  - CardView：卡牌视图基类
  - PlayfieldCardView：游戏区域卡牌视图
  - StackCardView：卡牌堆视图
- 卡牌属性：
  - CardFace：卡牌面值（0-12，代表A到K）
  - CardSuit：卡牌花色（0-3，代表四种不同花色）

 3.4 匹配区域系统
- 功能描述：处理卡牌匹配逻辑和显示
- 关键文件：
  - `MatchZoneController.cpp` - 匹配区域控制器
  - `MatchZoneView.cpp` - 匹配区域视图
- 关键组件：
  - MatchZoneController：匹配区域控制器，处理卡牌匹配逻辑
  - MatchZoneView：匹配区域视图，显示已匹配的卡牌
- 匹配规则：两张具有相同面值和花色的卡牌可以成功匹配

 3.5 撤销功能
- 功能描述：允许玩家撤销上一步操作
- 关键文件：
  - `UndoController.cpp` - 撤销操作控制器
  - `UndoView.cpp` - 撤销按钮视图
- 关键组件：
  - UndoController：撤销操作控制器，管理撤销栈
  - UndoView：撤销按钮视图，提供撤销交互界面
- 实现原理：记录每次操作的状态，撤销时恢复到上一个状态

 4. 技术栈与依赖

 4.1 开发语言
- C++

 4.2 游戏引擎
- cocos2d-x

 4.3 开发工具
- Visual Studio 2022 (v143编译器)
- Windows SDK 10.0.26100.0

 4.4 第三方库
- libcurl - 网络请求
- chipmunk - 物理引擎
- libSpine - 骨骼动画
- freetype - 字体渲染
- glew32 - OpenGL扩展库
- glfw3 - 窗口管理和输入处理
- libbox2d - 物理引擎
- libbullet - 物理引擎
- libchipmunk - 物理引擎
- libjpeg, libpng, libtiff, libwebp - 图像格式支持
- libmpg123, libogg, libvorbis, libvorbisfile - 音频格式支持
- sqlite3 - 数据库支持
- libcrypto, libssl - 加密和安全
- zlib - 数据压缩

 5. 构建与部署

 5.1 构建环境
- 操作系统：Windows
- IDE：Visual Studio 2022
- 编译器：MSVC v143
- Windows SDK：10.0.26100.0

 5.2 构建步骤
1. 打开 `TestCardGame.sln` 解决方案文件
2. 选择所需的配置（Debug/Release）和平台（Win32）
3. 点击"生成" -> "生成解决方案"或按F7进行构建

 5.3 输出文件
构建完成后，可执行文件和相关资源将生成在以下目录：
- Debug版本：`Debug.win32\TestCardGame.exe`
- Release版本：`Release.win32\TestCardGame.exe`

 5.4 资源部署
项目使用构建后事件自动复制资源文件：
```
if not exist "$(OutDir)" mkdir "$(OutDir)"
xcopy "$(ProjectDir)..\Resources" "$(OutDir)" /D /E /I /F /Y
```

 6. 配置文件说明

 6.1 关卡配置文件 - LevelConfig.json
该文件定义了游戏各关卡的初始状态，包括：
- Playfield：游戏区域初始卡牌布局和位置
- Stack：卡牌堆初始卡牌信息

配置文件格式示例：
```json
{
  "Level 1": [
    {
      "Playfield": [
        {
          "CardFace": 12,
          "CardSuit": 0,
          "Position": {
            "x": 250,
            "y": 1000
          }
        }
        // 更多卡牌...
      ],
      "Stack": [
        {
          "CardFace": 2,
          "CardSuit": 0,
          "Position": {
            "x": 0,
            "y": 0
          }
        }
        // 更多卡牌...
      ]
    }
  ]
}
```

 7. 运行环境要求

 7.1 硬件要求
- CPU：Intel Core i3或更高
- 内存：2GB或更高
- 显卡：支持OpenGL 2.0或更高的图形卡
- 硬盘空间：至少100MB可用空间

 7.2 软件要求
- 操作系统：Windows 7/8/10/11
- DirectX 9.0c或更高版本
- Visual C++ Redistributable for Visual Studio 2022

 8. 版本信息

- 当前版本：1.0.0.1
- 构建版本：Debug/Release

 9. 附录

 9.1 代码规范
- 采用C++命名约定，类名使用大驼峰命名法
- 函数和变量使用小驼峰命名法
- 文件组织结构遵循MVC设计模式
- 每个类和主要函数提供必要的注释

 9.2 常见问题与解决方案
- 问题：游戏无法启动
  解决方案：确保所有依赖的DLL文件与可执行文件在同一目录

- 问题：关卡加载失败
  解决方案：检查LevelConfig.json文件格式是否正确

- 问题：卡牌显示异常
  解决方案：确认resources\cards目录下的卡牌图片资源完整

 9.3 如何新增一张卡牌
要在游戏中新增一张卡牌，需要按照以下步骤进行操作：

 9.3.1 模型层修改
1. 在 `CardModel.cpp` 中添加新的卡牌类型定义：
   ```cpp
enum class CardType {
    NORMAL,       // 普通卡牌
    SPECIAL,      // 特殊卡牌
    WILD,         // 百搭卡牌（新增）
    // 可添加更多卡牌类型
};

// 在CardModel类中添加卡牌类型属性
class CardModel {
private:
    int cardFace;         // 卡牌面值
    int cardSuit;         // 卡牌花色
    CardType cardType;    // 卡牌类型

public:
    // 构造函数
    CardModel(int face, int suit, CardType type = CardType::NORMAL);
    
    // 获取和设置方法
    CardType getCardType() const { return cardType; }
    void setCardType(CardType type) { cardType = type; }
    
    // 其他现有方法...
};
```

2. 在 `GameModel.cpp` 中更新卡牌创建逻辑，支持创建新类型的卡牌：
   ```cpp
void GameModel::createCard(int face, int suit, CardType type, const Vec2& position) {
    auto card = std::make_shared<CardModel>(face, suit, type);
    // 添加卡牌到游戏中
    // ...
}
```

 9.3.2 视图层修改
1. 在 `CardView.cpp` 中添加新卡牌类型的视觉表示：
   ```cpp
void CardView::updateView() {
    // 现有逻辑
    
    // 根据卡牌类型显示不同的视觉效果
    switch (_cardModel->getCardType()) {
        case CardType::WILD:
            // 添加百搭卡牌的特殊视觉效果
            addWildCardEffect();
            break;
        // 其他卡牌类型...
    }
}
```

2. 为新卡牌类型准备相应的资源文件，放置在 `resources\cards\` 目录下

 9.3.3 控制器层修改
1. 在 `GameController.cpp` 中添加处理新卡牌类型的逻辑：
   ```cpp
void GameController::handleCardInteraction(CardView* cardView) {
    auto cardModel = cardView->getCardModel();
    
    // 现有逻辑
    
    // 处理特殊卡牌类型
    if (cardModel->getCardType() == CardType::WILD) {
        // 实现百搭卡牌的特殊逻辑
        handleWildCard(cardModel);
    }
}
```

2. 在 `MatchZoneController.cpp` 中更新匹配逻辑，支持新卡牌类型的匹配规则：
   ```cpp
bool MatchZoneController::canMatchCards(CardModel* card1, CardModel* card2) {
    // 现有逻辑
    
    // 百搭卡牌匹配逻辑
    if (card1->getCardType() == CardType::WILD || card2->getCardType() == CardType::WILD) {
        // 百搭卡牌可以匹配任何卡牌
        return true;
    }
    
    // 其他匹配逻辑
    return card1->getCardFace() == card2->getCardFace() && 
           card1->getCardSuit() == card2->getCardSuit();
}
```

 9.3.4 配置文件修改
在 `LevelConfig.json` 中添加包含新卡牌类型的关卡配置：
```json
{
  "Level 3": [
    {
      "Playfield": [
        // 现有卡牌配置...
        {
          "CardFace": 0,  // 面值可以是任意值，因为是百搭牌
          "CardSuit": 0,  // 花色可以是任意值，因为是百搭牌
          "CardType": 2,  // 2 表示百搭牌 (对应CardType::WILD枚举值)
          "Position": {
            "x": 500,
            "y": 800
          }
        }
      ],
      "Stack": [
        // 卡牌堆配置...
      ]
    }
  ]
}
```

 9.4 如何新增一种回退功能
要在游戏中新增一种回退功能，需要按照以下步骤进行操作：

 9.4.1 模型层修改
1. 创建一个新的操作历史记录模型类 `OperationHistoryModel.cpp`：
   ```cpp
// OperationType 枚举定义不同类型的操作
enum class OperationType {
    SELECT_CARD,     // 选择卡牌
    MATCH_CARDS,     // 匹配卡牌
    MOVE_CARD,       // 移动卡牌
    // 可添加更多操作类型
};

// 操作数据结构，存储操作的关键信息
struct OperationData {
    OperationType type;
    std::vector<int> cardIds;   // 涉及的卡牌ID
    std::map<std::string, std::string> params;  // 操作参数
    // 时间戳等其他信息
};

class OperationHistoryModel {
private:
    std::stack<OperationData> _operationStack;
    int _maxHistorySize;  // 最大历史记录数量

public:
    OperationHistoryModel(int maxSize = 50);
    
    // 记录操作
    void recordOperation(const OperationData& operation);
    
    // 获取上一个操作
    bool hasPreviousOperation() const;
    OperationData getPreviousOperation();
    
    // 清除历史记录
    void clearHistory();
};
```

2. 在 `GameModel.cpp` 中集成操作历史记录模型：
   ```cpp
class GameModel {
private:
    std::shared_ptr<OperationHistoryModel> _operationHistory;
    
    // 其他成员变量...

public:
    GameModel();
    
    // 获取操作历史
    std::shared_ptr<OperationHistoryModel> getOperationHistory() const { return _operationHistory; }
    
    // 记录各种操作的方法
    void recordCardSelection(int cardId);
    void recordCardMatch(const std::vector<int>& cardIds);
    // ...
};
```

 9.4.2 控制器层修改
1. 增强 `UndoController.cpp` 支持不同类型的回退操作：
   ```cpp
class UndoController {
private:
    std::shared_ptr<GameModel> _gameModel;
    std::shared_ptr<GameView> _gameView;
    
    // 其他成员变量...

public:
    UndoController(std::shared_ptr<GameModel> gameModel, 
                  std::shared_ptr<GameView> gameView);
    
    // 执行回退操作
    bool undoLastOperation();
    
private:
    // 处理不同类型的操作回退
    void undoCardSelection(const OperationData& operation);
    void undoCardMatch(const OperationData& operation);
    void undoCardMove(const OperationData& operation);
};
```

2. 在 `UndoController.cpp` 中实现回退逻辑：
   ```cpp
bool UndoController::undoLastOperation() {
    auto history = _gameModel->getOperationHistory();
    if (!history->hasPreviousOperation()) {
        return false;  // 没有可回退的操作
    }
    
    auto operation = history->getPreviousOperation();
    
    // 根据操作类型执行不同的回退逻辑
    switch (operation.type) {
        case OperationType::SELECT_CARD:
            undoCardSelection(operation);
            break;
        case OperationType::MATCH_CARDS:
            undoCardMatch(operation);
            break;
        case OperationType::MOVE_CARD:
            undoCardMove(operation);
            break;
    }
    
    return true;
}

void UndoController::undoCardMatch(const OperationData& operation) {
    // 实现匹配操作的回退逻辑
    // 1. 找到匹配的卡牌
    // 2. 将卡牌从匹配区域移回游戏区域
    // 3. 恢复卡牌状态
    // 4. 更新游戏视图
}
```

3. 在 `GameController.cpp` 中集成回退功能调用：
   ```cpp
void GameController::handleUndoButtonClick() {
    if (_undoController) {
        if (_undoController->undoLastOperation()) {
            // 更新游戏视图
            _gameView->update();
        }
    }
}
```

 9.4.3 视图层修改
1. 更新 `UndoView.cpp` 支持新的回退操作类型显示：
   ```cpp
void UndoView::updateView() {
    // 根据是否有可回退的操作启用/禁用按钮
    auto history = _gameModel->getOperationHistory();
    _undoButton->setEnabled(history->hasPreviousOperation());
    
    // 可选：显示下一个回退操作的类型
    if (history->hasPreviousOperation()) {
        auto nextUndo = history->getPreviousOperation();
        // 更新UI显示下一个回退操作的类型
        updateUndoTooltip(nextUndo);
    }
}
```

2. 为不同类型的回退操作添加相应的视觉反馈

 9.4.4 配置和设置
在游戏配置中添加回退功能的相关设置：
```cpp
// 在GameConfig.h中添加回退功能配置
struct GameConfig {
    // 其他配置...
    bool enableAdvancedUndo;  // 是否启用高级回退功能
    int maxUndoSteps;         // 最大回退步数
};
```

---
文档版本：1.0
