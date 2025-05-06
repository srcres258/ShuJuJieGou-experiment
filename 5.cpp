#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s, m, i, current_pos;
    vector<int> people, result;

    cin >> n >> s >> m;

    for (i = 1; i <= n; i++) {
        people.push_back(i);
    }

    current_pos = (s - 1) % n; // 处理s可能大于n的情况

    while (!people.empty()) {
        current_pos = (current_pos + m - 1) % people.size();
        result.push_back(people[current_pos]);
        people.erase(people.begin() + current_pos);
    }

    for (i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
