#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main() {
    int n, m, i, start_idx, cur;
    bool first;
    size_t j;

    cin >> n >> m;

    vector<string> vertex(n);
    map<string, int> v_index;
    for (i = 0; i < n; i++) {
        cin >> vertex[i];
        v_index[vertex[i]] = i;
    }

    vector<vector<int>> adj(n);
    for (i = 0; i < m; i++) {
        string u, v;
        cin >> u >> v;
        adj[v_index[u]].push_back(v_index[v]);
        adj[v_index[v]].push_back(v_index[u]);
    }

    string start;
    cin >> start;
    start_idx = v_index[start];

    vector<bool> visited(n, false);
    vector<vector<string>> result;

    // 处理起始顶点的连通分量
    if (!visited[start_idx]) {
        queue<int> q;
        vector<string> component;
        q.push(start_idx);
        visited[start_idx] = true;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            component.push_back(vertex[cur]);
            for (const auto &neighbor : adj[cur]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        result.push_back(component);
    }

    // 处理剩余未访问顶点
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            queue<int> q;
            vector<string> component;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                component.push_back(vertex[cur]);
                for (const auto &neighbor : adj[cur]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            result.push_back(component);
        }
    }

    cout << "BFS遍历结果：";
    first = false;
    for (const auto &comp : result) {
        if (!first) {
            cout << endl;
        }
        first = false;
        for (j = 0; j < comp.size(); j++) {
            if (j > 0) {
                cout << " -> ";
            }
            cout << comp[j];
        }
    }

    return 0;
}
