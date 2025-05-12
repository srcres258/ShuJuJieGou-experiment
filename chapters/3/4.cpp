#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

#define MAXN 1000  // 最大节点数，可根据需要调整

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjList[MAXN];
} Graph;

Graph *createGraph(int numVertices) {
    Graph *graph;
    int i;

    graph = new Graph;
    graph->numVertices = numVertices;
    for (i = 0; i < numVertices; i++) {
        graph->adjList[i] = nullptr;
    }

    return graph;
}

void addEdge(Graph *graph, int u, int v) {
    Node *newNode;

    newNode = new Node;
    newNode->vertex = v;
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    newNode = new Node;
    newNode->vertex = u;
    newNode->next = graph->adjList[v];
    graph->adjList[v] = newNode;
}

void dfs(Graph *graph, int v, int *visited) {
    Node *current;
    int neighbor;

    visited[v] = 1;
    current = graph->adjList[v];
    while (current) {
        neighbor = current->vertex;
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited);
        }
        current = current->next;
    }
}

int main() {
    int n, m, i, u, v, visited[MAXN], count;
    Graph *graph;

    cin >> n >> m;

    graph = createGraph(n);

    for (i = 0; i < m; i++) {
        cin >> u >> v;
        addEdge(graph, u, v);
    }

    memset(visited, 0, sizeof(visited));
    count = 0;

    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited);
            count++;
        }
    }

    cout << "连通分量个数: " << count << endl;

    return 0;
}
