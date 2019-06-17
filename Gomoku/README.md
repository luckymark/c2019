# 一个简单的五子棋（Gomoku） AI

## 五子棋简介

五子棋是世界智力运动会竞技项目之一，是一种两人对弈的纯策略型棋类游戏，通常双方分别使用黑白两色的棋子，下在棋盘直线与横线的交叉点上，先形成5子连线者获胜。
棋具与围棋通用，起源于中国上古时代的传统黑白棋种之一。主要流行于华人和汉字文化圈的国家以及欧美一些地区，是世界上最古老的棋。
容易上手，老少皆宜，而且趣味横生，引人入胜；不仅能增强思维能力，提高智力，而且富含哲理，有助于修身养性。已在各个游戏平台有应用。

本程序用C语言用控制台实现了五子棋程序，包括简易的界面，以及了一个较为~弱智~简单的AI。

## UI部分：[GomokuUI.h](/Gomoku/Gomoku/GomokuUI.h)

1. 定义结构`pointStruct`存储棋子的行和列.
棋子的值存储在`board[][]`数组里。  
`pointStruct`还包含一些对棋子的操作的函数，包括判断是否合法`valid()`，下棋`putPiece()`，移走棋子`remocePiece()`，取得其值`getChar()`。  

```c++
struct pointStruct {
    int column;
    int row;
    //some member functions
}
```

2. 程序启动以后，先让玩家选择先手还是后手。然后进入`runGame()`函数，让双方轮流下棋，并判定游戏的胜负（判定胜负由AI部分的函数计算得出）。  

3. `printBoard()` 函数用于打印棋盘，并可以根据程序开头的宏定义`#define`输出行、列数和每步运行时间和计算的次数。
4. `playerPutPiece()` 函数利用调用`cmd`的`choice`命令，实现不按回车即可完成输入，代码如下：

```c++
pointStruct playerPutPiece(int player, pointStruct curPoint) // move pointer to choose where to put c
{
	curPoint = putPieceAnyway(curPoint,POINTER_VALUE);
	int choice = 1;
	while (choice != 5)
	{
		pointStruct dir;
		printBoard();
		cout << R"str("O" is your piece, and "X" is AI's piece.)str" << endl
			<< "Please use asdw to move, and press p to put.";
		choice = system("choice /c asdwp");//a3 s6 d4 w1
		if (choice == 1) dir = { 0,-1 };
		else if (choice == 2) dir = { 1,0 };
		else if (choice == 3) dir = { 0,1 };
		else if (choice == 4) dir = { -1, 0 };
		else
			break;
		curPoint.removePiece();
		curPoint = curPoint + dir;
		curPoint = putPieceAnyway(curPoint, dir, POINTER_VALUE);
	}
	curPoint.putPiece(player);
	return curPoint;
}
```

5. `AIPutPiece()` 函数部分定义在[GomokuAI.h](README.md#AI部分：[GomokuAI.h](https://github.com/lyh543/c2019/blob/master/Gomoku/README.md#ai%E9%83%A8%E5%88%86gomokuaih)中

## AI部分：[GomokuAI.h](/Gomoku/GomokuAI.h)

1. 算法的第一个核心部分是对于棋局的判断。在董红安2005年论文《计算机五子棋博弈系统的研究与实现》中有这么一个评分表。
![score_table](/Gomoku/Gomoku/score_table.jpg)
用`pieceNInLine()`函数修改一个数组`len[]`，即为以该点为中心某一列的连续的棋子数。把该数组与由上述评分表生成的`scoreTable[][]`数组进行比对，即可得到每一行的估分。`calculateScore()`函数计算米字型的四个方向（米字型的八个方向，每一对相反的方向去掉其一，下同）上的分数并求和，即得到了该点的估分。  
同时，`pieceNInLine()`也实现了对胜局的判断，只需要判断返回的`len[]`数组其中是否有数大于等于5。
2. `AIPutPiece()`前两个版本使用的是`rand()`在可以下棋的范围内随机下棋，以及计算以上一个走子为中心的`9x9`（此处使用的是宏定义，可以根据效率和棋力进行调整）的格子中寻找分数最高的走法并走子。  
第三个版本中采用了决策树：每一步在`9x9`的范围进行搜索，搜索自己和对方的每一种走法，并把每一步作为一层、每一种走法作为一个节点建立决策树。  
a) 节点结构choiceTreeNode定义如下：

```c++
struct choiceTreeNode {
	int playerPiece;
	pointStruct point;
	int score();
	set<choiceTreeNode*> nextTreeNode;
	choiceTreeNode * fatherTreeNode;
};
```

储存了棋的坐标`point`、棋子颜色（下这步棋的人）`playerPiece`、以及指向父节点和子节点的指针。用`set`存储子节点的指针，因为同一个点的相同的子节点只需要考虑一次。  
`choiceTreeNode`还有一个成员函数`score()`，调用`calculateScore()`计算这个点的估值。由于决策树上的点的估值会受后面的棋局影响，因此需要动态计算。
由于`calucateScore()`函数是根据`board[][]`的值进行计算的，所以要计算某点的值时，必须要将前面的点全部放到棋盘上。具体实现的时候，是使用`DFS`+递归的`DFSChoiceTreeNode()`调用该函数，执行`DFSChoiceTreeNode()`都是先放上上一层节点对应的棋子，在进行新节点的递归计算，函数返回前再移除该节点。  
另外需要注意的是，在后面的函数中，调用该函数时有两种情况：一种是已经下了棋，要计算该处的估值；另一种是即将下这步棋，但是没有下。不清楚该棋子是否存在在当前的棋盘上，因此需要先尝试放置棋子，记录放置成功与否，然后再调用`CalculateScore()`函数，最后根据记录再决定是否移除该子。

b)	DFSChoiceTreeNode() 函数是建立决策树的核心部分，定义如下：

```c++
choiceTreeNode * DFSChoiceTreeNode(int curDepth, choiceTreeNode * lastTreeNode)
```

`DFS`的最大深度由`#define`宏定义为 4。在对深度大于 4、深度为 0 的情况进行特判以后，先把上一步的棋子放到棋盘上，再在上一步（对手棋）和上上一步（自己棋）的各自的`9x9`范围内进行搜索。由于玩家和AI搜索的方法略有不同，于是搜索分写为两个函数`getGoodChoiceForAI()`和`getGoodChoiceForPlayer()`.  
对于AI，应该先调用`DFSChoiceTreeNode()`递归得到该节点的所有在第4层的子节点，然后取这一节点（AI执子）的估值减上一节点（玩家执子）此时的估值的最大值的节点，然后返回（即先递归计算第4层，再求最大值，然后返回）；  
对于玩家，默认玩家只选择当前的最优解，作为一种剪枝手段，所以应该先得到所有的下一层子节点，取这一节点（玩家执子）的估值减上一节点（AI执子）此时的估值的最大值的节点，然后再调用`DFSChoiceTreeNode()`递归求第4层的子节点，然后返回（即先求下一层最大值，再递归计算第4层，然后返回）。  
另外一个值得注意的地方是，值为`NULL`的`choiceTreeNode`指针的定义。除了初始化的时候的`NULL`以外，剩余的`NULL`都是在该节点以下，AI必定输掉游戏，而不是AI/玩家范围内没有空格可以落子。由于代码过长，故略。  
c) 在`AIPutPiece()`函数的第三个版本中，主体是调用`DFSChoiceTreeNode()`，另外还有对数据的初始化、返回值的处理。由于`DFSChoiceTreeNode()`返回的是第四层的子节点，所以需要通过`choiceTreeNode`结构的`fatherTreeNode`向上递归到`lastNode`的子节点。如果返回的是`NULL`，根据定义在范围内走棋必输，因此调用`putPieceAnyway()`，找一个能下的节点即下棋。

## 总结

AI的棋力还比较弱，对于搜索范围内的走法比较准确，但是不会注意到搜索范围以外的。这直接导致对于算法很容易忽略掉活三（因为太长，堵了这一头，没有搜到那一头），导致输掉游戏。  
对于时间和内存占用，在每步棋对于搜索9x9范围，搜索深度为4层的情况下，每一步平均在5秒完成，内存占用在30MB左右。  
修改程序，使得程序每步棋都在整个11x11棋盘上搜索四层，第一步需要7分钟，消耗2GB内存。  

这是我编写的第一个“工程”。第一次写到多个文件的`C++`工程。第一次练习使用高度统一的变量名命名格式，使用`#define`，函数声明等在单个`cpp`文件的`C++`程序中不需要注意的要点。  
**To-do list**也是一个有必要的工作，它能把大问题分解为小问题，然后专心逐个攻破各个问题而暂时不用顾忌其他的问题。

## 改进建议（挖一些坑~~以后也不一定填~~）

1. 调试程序的时候,可以加入读档、存档的功能，这样可以更方便调试。
2. 算法容易忽略掉活三、冲四，一个原因是因为搜索范围不够大，第二是没有把活三、冲四拿出来单独考虑，就能很大程度的提升胜率；
3. 在`GomokuAI.h`的2. c)中，如果怎么走都会输掉比赛，应该接着进行全棋盘的搜索，这样才有可能不输掉游戏；
4. `Score()`并不一定完全需要动态计算，因为下一个棋，只更新这一个棋的米字型八个方向上的棋子的`Score`，可以把每个节点的`Score`分为四个方向存储，获取的时候就把四个值相加，下一个棋的时候在动态修改它方向上的棋子的节点值；
5. 可以用`Qt`写一个Windows窗口的UI；
6. 以后可以把程序改为多线程、或用GPU运算，能在硬件上大幅运行速度。
