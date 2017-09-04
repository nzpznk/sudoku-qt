# sudoku-qt
A qt version sudoku game.

## 实现功能：

1. 实现标准9X9布局，响应鼠标点击。

2. 点击选中方格可对选中方格填数，通过选中数字按钮进行填数。

3. 实现重玩、暂停功能（暂停时计时停止，方格不可选中）

4. 实现关卡选择（10+个不同难度的关卡）（难度可使用初始空格的数目，或是其他合理方式确定）

5. 实现撤销、恢复功能（支持撤销10步）

6. 实现删除功能。

7. 点击数字亮显当前界面所有相同数字，高亮选中数字所在行列

8. 支持标记和输入量中模式，标记模式下方格内填多个数字。

9. 能正确判定当前填入数字中是否有错误并指出

10. 数独问题产生器，可以随机产生数独游戏

11. 数独问题求解器。

## 运行效果：

1. 能对格子选中，高亮，标记，显示是否错误

![](https://github.com/nzpznk/sudoku-qt/blob/master/show/show1.PNG)

2. 能够高效而正确地求解

![](https://github.com/nzpznk/sudoku-qt/blob/master/show/show2.PNG)

## 模块划分：

### 主逻辑 (`./logic` 文件夹下)

| 类 | 功能 |
| -- | -- |
| LogicController | 控制游戏主逻辑，诸如重玩，撤销与回撤，正确性检查，发送信号更新界面 |

### 界面 (`./UI` 文件夹下)

| 类 | 功能 |
| -- | -- |
| MainWindow | 用于选择关卡 |
| GameBoard | 游戏界面 |
| SudokuGrid | 数独格子组件 |
| Inputboard | 输入数字框组件 |
| GridBtn | 继承QLabel而写成的按钮控件 |

### 求解器 （`./solver` 文件夹下）

| 类 | 功能 |
| -- | -- |
| Solver | Algorithm X 的抽象算法，实现为一个函数对象，通过调用DancingLinks接口描述
| DancingLinks | 实现dancinglinks基本操作，数据底层操作调用DLNodesContainer的实现 |
| DLNodesContainer | 链表节点的容器，规定了DancingLinks操作所需的底层基本操作，继承重写可以实现不同种类数独 |
| StdSudokuNodesContainer | 用于表示9 x 9标准数独的DLNodesContainer |

### 数独加载 (`./loader` 文件夹下)

| 类 | 功能 |
| -- | -- |
| Loader | 所有加载器的基类，暴露唯一对外界有用的接口`Loader::load()`方法 |
| FileLoader | 通过磁盘文件资源进行加载，实现功能中的关卡设计 |
| RandomGenerator | 随机生成数独游戏 |

## 关于求解与生成算法

1. 求解算法使用dancinglinks数据结构，使用 [Algorithm X](https://en.wikipedia.org/wiki/Knuth%27s_Algorithm_X) 进行求解

2. 生成算法使用知乎用户提供的[一种方法](https://www.zhihu.com/question/22043229)：(1) 随机生成11个位置，调用solver计算一个解答形成终盘。(2) 之后随机挖洞，每挖一个洞调用 [Algorithm X](https://en.wikipedia.org/wiki/Knuth%27s_Algorithm_X) 判断解答是否唯一，如果不唯一就回溯

3. 随机生成难度控制：可以通过生成步骤(2)中的随机尝试次数进行控制，实验发现尝试次数30次左右可以产生简单难度的数独，尝试次数达到接近100次左右数独的空格数可以达到50个左右，效果相当显著
