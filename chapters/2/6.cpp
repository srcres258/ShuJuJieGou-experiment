#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    char value;
    int left;
    int right;
};

int main() {
    int n, i, l, r, k, count, current, right, left;
    char val, result;
    stack<int> st;

    cin >> n;
    vector<TreeNode> nodes(n);
    for (i = 0; i < n; i++) {
        cin >> val >> l >> r;
        nodes[i].value = val;
        nodes[i].left = l;
        nodes[i].right = r;
    }
    cin >> k;

    st.push(0); // 根节点的索引为0
    count = 0;
    
    while (!st.empty()) {
        current = st.top();
        st.pop();
        count++;
        if (count == k) {
            result = nodes[current].value;
            break;
        }
        // 先压右子节点，再压左子节点
        right = nodes[current].right;
        if (right != -1) {
            st.push(right);
        }
        left = nodes[current].left;
        if (left != -1) {
            st.push(left);
        }
    }

    cout << result << endl;

    return 0;
}
