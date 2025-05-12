#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

void create_graph(
    vector<vector<int>> &graph,
    int n,
    int e,
    const unordered_map<string, int> &vertex_map
) {
    int i, idx1, idx2;

    for (i = 0; i < e; i++) {
        string v1, v2;
        cin >> v1 >> v2;
        idx1 = vertex_map.at(v1);
        idx2 = vertex_map.at(v2);
        graph[idx1][idx2] = 1;
        graph[idx2][idx1] = 1;
    }
}

void print_graph(const vector<vector<int>> &graph) {
    size_t j;
    
    for (const auto &row : graph) {
        for (j = 0; j < row.size(); j++) {
            if (j != 0) {
                cout << ' ';
            }
            cout << row[j];
        }
        cout << endl;
    }
}

int main() {
    int n, e, i;

    cin >> n >> e;
    vector<string> vertices(n);
    for (i = 0; i < n; i++) {
        cin >> vertices[i];
    }
    unordered_map<string, int> vertex_map;
    for (i = 0; i < n; i++) {
        vertex_map[vertices[i]] = i;
    }
    vector<vector<int>> graph(n, vector<int>(n, 0));
    create_graph(graph, n, e, vertex_map);
    cout << "邻接矩阵:" << endl;
    print_graph(graph);

    return 0;
}
