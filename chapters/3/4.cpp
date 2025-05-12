/*
请根据下面题目要求，将所给C++代码补充完整（可修改代码任意位置）。

# 题目

采用邻接表存储结构，编写一个求无向图的连通分量个数的算法。

# 样例1

输入：

```
5 3
0 1
1 2
3 4
```

输出：

```
连通分量个数: 2
```

说明：

```
请输入节点数 n 和边数 m:
6 4
请输入每条边的两个节点编号（0到n-1）：
0 1
2 3
3 4
4 2
```

# 样例2

输入：

```
6 4
0 1
2 3
3 4
4 2
```

输出：

```
连通分量个数: 3
```

说明：

```
请输入节点数 n 和边数 m:
6 4
请输入每条边的两个节点编号（0到n-1）：
0 1
2 3
3 4
4 2
```
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000  // 最大节点数，可根据需要调整

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjList[MAXN];
} Graph;

int main() {
    
}
