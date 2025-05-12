#include <iostream>
#include <vector>
using namespace std;

const int MVNum = 100; // 最大顶点数
bool visited[MVNum];   // 全局访问标记数组

typedef char VerTexType;              
typedef int ArcType;                   

// 图的邻接矩阵存储表示
typedef struct {
	VerTexType vexs[MVNum];            
	ArcType arcs[MVNum][MVNum];        
	int vexnum, arcnum;                
} AMGraph;

// 定位顶点
int LocateVex(AMGraph G, VerTexType v) {
	int i;

    for (i = 0; i < G.vexnum; i++) {
        if (G.vexs[i] == v) {
            return i;
        }
    }

    return -1; // 没有找到
}

// 找第一个邻接顶点
int FirstAdjVex(AMGraph G, int v) {
	int j;

    for (j = 0; j < G.vexnum; j++) {
        if (G.arcs[v][j] != 0) {
            return j;
        }
    }

    return -1; // 没有找到
}

// 找v相对于w的下一个邻接顶点
int NextAdjVex(AMGraph G, int v, int w) {
	int j;

    for (j = w + 1; j < G.vexnum; j++) {
        if (G.arcs[v][j] != 0) {
            return j;
        }
    }

    return -1; // 没有找到
}

// 创建无向图
void CreateUDG(AMGraph &G) {
	int i, j, k;
    VerTexType v1, v2;
    
    cin >> G.vexnum >> G.arcnum;

    for (i = 0; i < G.vexnum; i++) {
        cin >> G.vexs[i];
    }

    for (i = 0; i < G.vexnum; i++) {
        for (j = 0; j < G.vexnum; j++) {
            G.arcs[i][j] = 0;
        }
    }

    for (k = 0; k < G.arcnum; k++) {
        cin >> v1 >> v2;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j] = 1;
        G.arcs[j][i] = 1;
    }
}

// 深度优先搜索遍历单个连通分量
void DFS(AMGraph &G, int v) {
    int w;
    
	cout << G.vexs[v] << " ";
    visited[v] = true;
    for (
        w = FirstAdjVex(G, v);
        w >= 0;
        w = NextAdjVex(G, v, w)
    ) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
}

// 遍历整个图，包括所有连通分量
void DFSTraverse(AMGraph &G, int start) {
	int i, v;
    bool firstComponent;

    for (i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }

    cout << "深度优先遍历:" << endl;
    firstComponent = true;

    if (!visited[start]) {
        cout << "{ ";
        DFS(G, start);
        cout << "}";
        firstComponent = false;
    }

    for (v = 0; v < G.vexnum; v++) {
        if (!visited[v]) {
            if (!firstComponent) {
                cout << endl << "{ ";
            } else {
                cout << "{ ";
                firstComponent = false;
            }
            DFS(G, v);
            cout << "}";
        }
    }
    cout << endl;
}

// 打印邻接矩阵
void PrintMatrix(AMGraph &G) {
    int i, j;
    
    cout << "邻接矩阵:" << endl;
    for (i = 0; i < G.vexnum; i++) {
        for (j = 0; j < G.vexnum; j++) {
            cout << G.arcs[i][j];
            if (j != G.vexnum - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    AMGraph G;
    VerTexType start;
    int startIndex;

    CreateUDG(G);

    cin >> start;
    startIndex = LocateVex(G, start);

    PrintMatrix(G);
    DFSTraverse(G, startIndex);

    return 0;
}
