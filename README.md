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
  - （DONE）conflict(int row, int column, QString& message)

2. slots:
  - （DONE	）changeNum(int value, int row, int column)

### 用例设想：

1. 每接收到一个setNumber() 的signal，调用changeNum设置这个数字，并判断是否发生了冲突

2. 如果发生冲突，发射一个conflit(int rank1, int rank2)的signal

3. 判断是否游戏结束，如果结束就发射congratulation()信号







## 数独生成器部分：

### 职责：

1. 通过给定的难度生成一个解答矩阵和mask列表

【生成】的过程是随机的。
一、生成过程如下：（现在出题一般都由计算机完成）
0、求解子程序。这个子程序可用dancing links算法，不是逻辑解法。可以在非唯一解的情况下找到任意一个解。
1、随机放入11个数，用0中的子程序求任意解生成终盘。（相关研究表明，放入11个数，有解的概率约99.7%，12个数有解概率降低不少，10个数虽然概率更高，但求解时间增长。故11个合适。）
2、生成终盘后，不断随机挖掉一个数。每次挖掉一个数，检查是否存在唯一解。方法：如果挖掉一个1，在该方格中依次填入2～9，调用0中的子程序求解。
3、判断难度。比较简单的方法是，计算每一个空格有多少个候选数，总候选数越多，可能越难。不保证有逻辑解。
高端一点的方法是，另写一个逻辑求解子程序，给各种逻辑解法打分，如各种排除法1.x，各种wing2.x，更高的可能有6.x等等。总分数越高，代表越难。

题主所说的保证有逻辑解，并提高难度，肯定不是靠人脑。
而是由机器批量出题，再评定难度。
依陈岑老师的说法，前两年的“最难数独”难度为10.7，现在出现了11+的。可能每出几万道题才能碰上一个8+的。所以只能靠机器了。

作者：单想
链接：https://www.zhihu.com/question/22043229/answer/44315364
来源：知乎
著作权归作者所有，转载请联系作者获得授权。







## Solver 部分

### 职责：

1. 接受一个数独矩阵

2. 构建描述数独的dancing links

3. 使用算法X求解

### api：

1. 接受一个matrix构造一个solver

2. 一个solve(matrix)的函数，用于求解

3. 如果唯一解，返回解答，否则返回一个特定值

4. 一个动态插入填入数据的接口insert()，动态删除数据的接口remove()








## Dancing Links

### api：

1. construct() 构造一个完整的dl

2. choose(val, i, j) 返回一个vector包含所有被移除的行和列

// 隐含removeRow() removeCol()

3. backtrack() 用于将上一步改动复位









