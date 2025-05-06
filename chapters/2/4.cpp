#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    char value;
    int left;
    int right;
};

// 递归计算叶子节点数目
int countLeaves(const vector<TreeNode> &nodes, int index) {
    if (index == -1) {
        return 0;
    }
    auto &node = nodes[index];
    if (node.left == -1 && node.right == -1) {
        return 1;
    }
    return countLeaves(nodes, node.left) + countLeaves(nodes, node.right);
}

int main() {
    int n, i, l, r;
    char val;

    cin >> n;
    vector<TreeNode> nodes(n);
    for (i = 0; i < n; i++) {
        cin >> val >> l >> r;
        nodes[i].value = val;
        nodes[i].left = l;
        nodes[i].right = r;
    }
    cout << countLeaves(nodes, 0) << endl;

    return 0;
}
