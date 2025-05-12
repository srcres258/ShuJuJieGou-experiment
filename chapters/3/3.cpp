#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MVNum = 100; 
bool visited[MVNum];

typedef char VerTexType;              
typedef int ArcType;                   

typedef struct {
	VerTexType vexs[MVNum];            
	ArcType arcs[MVNum][MVNum];        
	int vexnum, arcnum;                
} AMGraph;

int LocateVex(AMGraph G, VerTexType v) {
	int i;

    for (i = 0; i < G.vexnum; i++) {
        if (G.vexs[i] == v) {
            return i;
        }
    }

    return -1; // 没有找到
}

int FirstAdjVex(AMGraph G, int v) {
	int i;

    for (i = 0; i < G.vexnum; i++) {
        if (G.arcs[v][i] != 0) {
            return i;
        }
    }

    return -1; // 没有邻接点
}

int NextAdjVex(AMGraph G, int v, int w) {
	int i;

    for (i = w + 1; i < G.vexnum; i++) {
        if (G.arcs[v][i] != 0) {
            return i;
        }
    }

    return -1; // 没有下一个邻接点
}

void CreateUDG(AMGraph &G) {
    int i, j, k;
    VerTexType v1, v2;

	cin >> G.vexnum >> G.arcnum;
    for (i = 0; i < G.vexnum; i++) {
        cin >> G.vexs[i];
    }
    memset(G.arcs, 0, sizeof(G.arcs));
    for (k = 0; k < G.arcnum; k++) {
        cin >> v1 >> v2;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j] = 1;
        G.arcs[j][i] = 1;
    }
}

void BFS(AMGraph &G, int v) {
	queue<int> q;
    int u, w;
    
    cout << G.vexs[v] << " ";
    visited[v] = true;
    q.push(v);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (
            w = FirstAdjVex(G, u);
            w >= 0;
            w = NextAdjVex(G, u, w)
        ) {
            if (!visited[w]) {
                cout << G.vexs[w] << " ";
                visited[w] = true;
                q.push(w);
            }
        }
    }
}

void BFSTraverse(AMGraph &G, VerTexType startVex) {
	int start, i;
    
    memset(visited, false, sizeof(visited));
    start = LocateVex(G, startVex);
    cout << "广度优先遍历:" << endl;
    if (start != -1 && !visited[start]) {
        cout << "{ ";
        BFS(G, start);
        cout << "}" << endl;
    }
    for (i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            cout << "{ ";
            BFS(G, i);
            cout << "}" << endl;
        }
    }
}

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
    VerTexType startVex;

    CreateUDG(G);
    PrintMatrix(G);
    cin >> startVex;
    BFSTraverse(G, startVex);

    return 0;
}
