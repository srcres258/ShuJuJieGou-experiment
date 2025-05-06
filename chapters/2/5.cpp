#include <iostream>
#include <vector>

using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    char value;
    int left;
    int right;
};

void preOrder(
    int index,
    int &count,
    int K,
    char &res,
    const vector<TreeNode> &nodes
) {
    if (index == -1 || res != '\0') {
        return;
    }
    count++;
    if (count == K) {
        res = nodes[index].value;
        return;
    }
    preOrder(nodes[index].left, count, K, res, nodes);
    preOrder(nodes[index].right, count, K, res, nodes);
}

int main() {
    int n, i, l, r, K, count;
    char val, res;
    
    cin >> n;
    vector<TreeNode> nodes(n);
    for (i = 0; i < n; i++) {
        cin >> val >> l >> r;
        nodes[i].value = val;
        nodes[i].left = l;
        nodes[i].right = r;
    }
    cin >> K;
    count = 0;
    res = '\0';
    preOrder(0, count, K, res, nodes);
    cout << res << endl;

    return 0;
}
