# sudoku-qt
A qt version sudoku game.

## gameboard界面

### 想法

1. （DONE）写一个for循环，将格子存在一个数组中

2. 给定一个数独矩阵显示出来

3. 边框线的绘制

4. 尺寸的弹性控制（line edit)



### gameboard 部分职责

1. （DONE）line_edit的valueChange信号的映射

2. 对用户输入的响应(错误输入(冲突输入)弹出警告)

## gameboard 部分的api

1. signals:
  - （DONE）setNumber(int value, int row, int column)

2. slots:
  - showWarning(int row, int column, QString& msg)
  - initialize(matrix)
  //- undo() 通过维护一个操作栈实现
  //- restart()

### 用例设想：

1. 初始的时候展示 9 * 9 方格, 所有的line_edit都是禁用状态，被调用initialize槽的时候进行初始化

2. 用户每填充一个格子都检查合法性，如果合法(是1~9的数字)就发送一个setNumber()的signal

3. 当showMessage()槽被调用的时候，相关的log出相应的警示信息

## 数独逻辑部分：

### api:

1. signals:
  - initGame(matrix)
  - congratulation()

2. slots:
  - changeNum(int value, int row, int column)
  - conflict(int row, int column, QString& message)


















