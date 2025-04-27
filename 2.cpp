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

    /**
     * 插入结点到指定索引的结点后。
     */
    void append(int val, int index) {
        ListNode *curr, *next;
        int i;

        curr = head;
        for (i = 0; i < index; i++) {
            if (!curr) {
                return;
            }
            curr = curr->next;
        }
        if (curr) {
            next = curr->next;
            curr->next = new ListNode(val);
            curr->next->next = next;
        }
    }

    /**
     * 删除指定索引的结点。
     */
    void deleteIndex(int index) {
        ListNode *curr, *prev;
        int i;

        prev = nullptr;
        curr = head;
        for (i = 0; i < index; i++) {
            if (!curr) {
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        if (prev) {
            prev->next = curr->next;
        } else {
            head = curr->next;
        }
        delete curr;
    }

    /**
     * 删除结点值与给定值相等的结点。
     */
    void deleteValue(int val) {
        ListNode *curr, *prev;
        int i;

        prev = nullptr;
        curr = head;
        while (curr) {
            if (curr->data == val) {
                // 找到结点了，将其删除。
                if (prev) {
                    prev->next = curr->next;
                } else {
                    head = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};

int main() {
    LinkedList list;
    int a, b, i, val;

    // 输入一个数a，后面将输入a个数据元素，依次插入尾结点后。
    std::cin >> a;
    for (i = 0; i < a; i++) {
        std::cin >> val;
        list.append(val);
    }

    // 输入一个数b，后面将再输入b个数据元素，依次插入0号结点后。
    std::cin >> b;
    for (i = 0; i < b; i++) {
        std::cin >> val;
        list.append(val, 0);
    }
    
    // 删除指定值的结点
    std::cin >> val;
    list.deleteValue(val);

    // 删除指定索引的结点
    std::cin >> i;
    list.deleteIndex(i);

    // 打印链表
    list.print();

    return 0;
}