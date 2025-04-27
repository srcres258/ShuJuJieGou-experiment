#include <iostream>

struct Node {
    int coefficient;
    int exponent;
    Node *next;

    Node(int c, int e) : coefficient(c), exponent(e), next(nullptr) {}
};

class Polynomial {
public:
    Node *head;

    Polynomial() : head(nullptr) {}

    void addTerm(int coefficient, int exponent) {
        Node *temp;
        
        if (coefficient == 0) {
            return;
        }
        if (head) {
            temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = new Node(coefficient, exponent);
        } else {
            head = new Node(coefficient, exponent);
        }
    }

    void print() const {
        using namespace std;

        Node *temp;
        bool first;

        temp = head;
        if (!temp) {
            cout << "0" << endl;
            return;
        }
        first = true;
        cout << "C(x)=A(x) + B(x) = ";
        while (temp) {
            if (!first) {
                if (temp->coefficient > 0) {
                    cout << " + ";
                } else {
                    // 不需要输出减号，输出系数时会自动包含符号。
                    cout << " ";
                }
            }
            first = false;
            if (temp->exponent == 0) {
                // 常数项。
                cout << temp->coefficient;
            } else {
                cout << temp->coefficient << "x^" << temp->exponent;
            }
            temp = temp->next;
        }
        cout << endl;
    }

    ~Polynomial() {
        Node *current, *next;

        current = head;
        while (current) {
            next = current->next;
            delete current;
            current = next;
        }
    }
};

Polynomial addPolynomials(const Polynomial *A, const Polynomial *B) {
    Polynomial C;
    Node *a, *b, *tail, *newNode;
    int sum;

    a = A->head;
    b = B->head;
    tail = nullptr;

    while (a || b) {
        newNode = nullptr;

        if (!a) {
            newNode = new Node(b->coefficient, b->exponent);
            b = b->next;
        } else if (!b) {
            newNode = new Node(a->coefficient, a->exponent);
            a = a->next;
        } else if (a->exponent < b->exponent) {
            newNode = new Node(a->coefficient, a->exponent);
            a = a->next;
        } else if (a->exponent > b->exponent) {
            newNode = new Node(b->coefficient, b->exponent);
            b = b->next;
        } else {
            sum = a->coefficient + b->coefficient;
            if (sum) {
                newNode = new Node(sum, a->exponent);
            }
            a = a->next;
            b = b->next;
        }

        if (newNode) {
            if (C.head) {
                tail = newNode;
                C.head = tail;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    return C;
}

int main() {
    using namespace std;

    Polynomial A, B;
    int highestA, highestB, i, coeff;

    cin >> highestA;
    for (i = 0; i <= highestA; i++) {
        cin >> coeff;
        A.addTerm(coeff, i);
    }

    cin >> highestB;
    for (i = 0; i <= highestB; i++) {
        cin >> coeff;
        B.addTerm(coeff, i);
    }

    auto C = addPolynomials(&A, &B);
    C.print();

    return 0;
}