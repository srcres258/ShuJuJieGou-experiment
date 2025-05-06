#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x, i, pos;
    vector<int> *a;
    size_t i1;

    cin >> n;
    a = new vector<int>(n);
    for (i = 0; i < n; i++) {
        cin >> a->at(i);
    }
    cin >> x;

    // 寻找插入位置。
    pos = 0;
    while (pos < a->size() && a->at(pos) < x) {
        pos++;
    }
    a->insert(a->begin() + pos, x);

    // 输出结果，确保末尾无多余空格。
    if (!a->empty()) {
        cout << a->at(0);
        for (i1 = 1; i1 < a->size(); i1++) {
            cout << " " << a->at(i1);
        }
    }
    cout << endl;

    delete a;

    return 0;
}