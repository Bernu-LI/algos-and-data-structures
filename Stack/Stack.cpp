#include <iostream>

using namespace std;

struct stack {
    struct node {
        node(int v): value(v){}
        int value;
        node* next = nullptr;
    };

    node* head = nullptr;

    int size_value = 0;

    void push (int number) {
        node* new_el = new node(number);
        if (head == nullptr) {
            head = new_el;
        }
        else {
            new_el->next = head;
            head = new_el;
        }
        size_value++;
    }

    void pop() {
        if (head == nullptr) {
            cout << "Nothing to remove\n";
            return;
        }
        else {
            if (head -> next == nullptr) {
                delete(head);
                head = nullptr;
            }
            else {
                node* temp = head;
                head = head->next;
                delete(temp);
            }
            size_value--;
        }
    }

    int top() {
        return head->value;
    }

    int size() {
        return size_value;
    }

    void print() {
        if (head == nullptr) {
            cout << "No elements" << "\n";
        }
        else {
            node* auxiliary_variable = head;
            while (auxiliary_variable != 0) {
                cout << auxiliary_variable->value << " ";
                auxiliary_variable = auxiliary_variable->next;
            }
        }
    }
};

int main() {
    stack s1;
    s1.pop();
    s1.push(1);
    s1.pop();
    cout << s1.head << "\n";
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    cout << s1.size() << "\n";
    s1.print();
    return 0;
}
