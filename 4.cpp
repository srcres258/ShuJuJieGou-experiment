#include <iostream>

struct Term {
    int coef;
    int exp;
    Term *next;

    Term(int c, int e) : coef(c), exp(e), next(nullptr) {}
};

int main() {
    using namespace std;

    int max_exp, exp, coef, sum, abs_coef;
    Term *ha, *hb, *hc, *tail, *new_node, *p, *q, *curr;
    Term dummy(0, 0);
    bool first;

    ha = nullptr;
    hb = nullptr;
    
    // 构建多项式A
    cin >> max_exp;
    for (exp = 0; exp <= max_exp; exp++) {
        cin >> coef;
        if (coef) {
            new_node = new Term(coef, exp);
            if (ha) {
                tail->next = new_node;
                tail = new_node;
            } else {
                tail = new_node;
                ha = tail;
            }
        }
    }

    // 构建多项式B
    cin >> max_exp;
    for (exp = 0; exp <= max_exp; exp++) {
        cin >> coef;
        if (coef) {
            new_node = new Term(coef, exp);
            if (hb) {
                tail->next = new_node;
                tail = new_node;
            } else {
                tail = new_node;
                hb = tail;
            }
        }
    }

    // 合并多项式
    tail = &dummy;
    p = ha;
    q = hb;
    while (p && q) {
        if (p->exp < q->exp) {
            tail->next = new Term(p->coef, p->exp);
            tail = tail->next;
            p = p->next;
        } else if (p->exp > q->exp) {
            tail->next = new Term(q->coef, q->exp);
            tail = tail->next;
            q = q->next;
        } else {
            sum = p->coef + q->coef;
            if (sum != 0) {
                tail->next = new Term(sum, p->exp);
                tail = tail->next;
            }
            p = p->next;
            q = q->next;
        }
    }
    while (p) {
        tail->next = new Term(p->coef, p->exp);
        tail = tail->next;
        p = p->next;
    }
    while (q) {
        tail->next = new Term(q->coef, q->exp);
        tail = tail->next;
        q = q->next;
    }
    hc = dummy.next;

    // 输出结果
    cout << "C(x)=A(x) + B(x) = ";
    if (hc) {
        first = true;
        for (curr = hc; curr; curr = curr->next) {
            if (first) {
                if (curr->coef < 0) {
                    cout << "-";
                }
                first = false;
            } else {
                if (curr->coef > 0) {
                    cout << " + ";
                } else {
                    cout << " - ";
                }
            }

            abs_coef = abs(curr->coef);
            if (abs_coef != 1 || curr->exp == 0) {
                cout << (first ? curr->coef : abs_coef);
            }

            if (curr->exp > 0) {
                cout << "x^" << curr->exp;
            }
            if (first) {
                first = false;
            }
        }
    } else {
        cout << "0";
    }
    cout << endl;

    return 0;
}