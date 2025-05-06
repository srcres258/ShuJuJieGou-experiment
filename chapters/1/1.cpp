#include <iostream>

/**
 * 定义链表节点结构。
 */
struct ListNode {
    int data;
    ListNode *next;

    ListNode(int val) : data(val), next(nullptr) {}
};

/**
 * 单链表类封装。
 */
class LinkedList {
private:
    /**
     * 链表头节点指针。
     */
    ListNode *head;

    /**
     * 递归释放内存的辅助函数。
     */
    void clear(ListNode *node) {
        if (!node) {
            return;
        }

        clear(node->next);
        delete node;
    }

public:
    /**
     * 构造函数初始化空链表。
     */
    LinkedList() : head(nullptr) {}

    /**
     * 析构函数自动释放内存。
     */
    ~LinkedList() {
        clear(head);
    }

    /**
     * 创建链表的辅助函数（数组版本）。
     */
    void createFromArray(int arr[], int n) {
        ListNode *curr;
        int i;
        
        if (n <= 0) {
            return;
        }
        head = new ListNode(arr[0]);
        curr = head;
        for (i = 1; i < n; i++) {
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }
    }

    /**
     * 打印链表的辅助函数。
     */
    void print() const {
        ListNode *curr;

        curr = head;
        while (curr) {
            std::cout << curr->data;
            if (curr->next) {
                std::cout << " ";
            }
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    /**
     * 向链表末尾追加结点。
     */
    void append(int val) {
        ListNode *curr;
        
        if (!head) {
            head = new ListNode(val);
            return;
        }

        curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new ListNode(val);
    }
};

int main() {
    LinkedList list;
    int n, i, tmp;

    std::cin >> n;
    for (i = 0; i < n; i++) {
        std::cin >> tmp;
        list.append(tmp);
    }
    std::cout << "链表创建成功！链表内容为：" << std::endl;
    list.print();

    return 0;
}