#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAXN 1000

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjList[MAXN];
} Graph;

int visited[MAXN];
int found;

void dfs(Graph *graph, int v, int j) {
    Node *current;
    int neighbor;

    if (v == j) {
        found = 1;
        return;
    }
    visited[v] = 1;
    current = graph->adjList[v];
    while (current && !found) {
        neighbor = current->vertex;
        if (!visited[neighbor]) {
            dfs(graph, neighbor, j);
        }
        current = current->next;
    }
}

int main() {
    int n, m, i, j, k, u, v;
    Graph graph;
    Node *newNode;

    cin >> n >> m;

    graph.numVertices = n;
    for (i = 0; i < n; i++) {
        graph.adjList[i] = nullptr;
    }

    for (k = 0; k < m; k++) {
        cin >> u >> v;
        newNode = new Node;
        newNode->vertex = v;
        newNode->next = graph.adjList[u];
        graph.adjList[u] = newNode;
    }

    cin >> i >> j;

    for (k = 0; k < n; k++) {
        visited[k] = 0;
    }
    found = 0;

    dfs(&graph, i, j);

    if (found) {
        cout << "存在从V" << i << "到V" << j << "的路径" << endl;
    } else {
        cout << "不存在从V" << i << "到V" << j << "的路径" << endl;
    }

    // 省略堆内存的释放
    return 0;
}
