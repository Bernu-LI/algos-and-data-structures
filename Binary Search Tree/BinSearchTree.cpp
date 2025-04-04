#include <iostream>

using namespace std;

struct SearchTree {
    struct node {
        node(long long v): value(v) {}
        long long value;
        node* left = nullptr;
        node* right = nullptr;
        node* parent = nullptr;
    };

    node* root = nullptr;

    void insert(long long num) {
        node* new_el = new node(num);
        if (root == nullptr) {
            root = new_el;
        }
        else {
            node* temp = root;
            while (true) {
                if (num <= temp->value) {
                    if (temp->left == nullptr) {
                        temp->left = new_el;
                        new_el->parent = temp;
                        break;
                    }
                    else {
                        temp = temp->left;
                    }
                }
                else if (num > temp->value) {
                    if (temp->right == nullptr) {
                        temp->right = new_el;
                        new_el->parent = temp;
                        break;
                    }
                    else {
                        temp = temp->right;
                    }
                }
            }
        }
    }

    void inOrderTraversal(node* el, vector <long long>* v) {
        if (el != nullptr) {
            inOrderTraversal(el->left, v);
            v->push_back(el->value);
            inOrderTraversal(el->right, v);
        }
    }

    node* next(long long number) {
        vector <long long> v;
        inOrderTraversal(root, &v);
        for (long long i = 0; i < v.size(); i++) {
            if (v[i] > number) {
                return exists(v[i]);
            }
        }
        return nullptr;
    }

    node* prev(long long number) {
        vector <long long> v;
        inOrderTraversal(root, &v);
        for (long long i = v.size() - 1; i >= 0; i--) {
            if (v[i] < number) {
                return exists(v[i]);
            }
        }
        return nullptr;
    }

    node* searchNext(node* el) {
        if (el->right != nullptr) {
            node* temp = el->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            return temp;
        }
        else {
            node* temp = el->parent;
            while (temp != nullptr and temp->parent->left != temp) {
                temp = temp->parent;
            }
            if (temp == nullptr) {
                return nullptr;
            }
            else {
                return temp->parent;
            }
        }
    }

    void pop1(node* el) {
        if (el->parent == nullptr) {
            root = nullptr;
        }
        else if (el->parent->left == el) {
            el->parent->left = nullptr;
        }
        else if (el->parent->right == el) {
            el->parent->right = nullptr;
        }
        delete el;
    }
    void pop2(node* el) {
        if (el->parent == nullptr) {
            if (el->right != nullptr) {
                root = el->right;
            }
            else if (el->left != nullptr) {
                root = el->left;
            }
        }
        else if (el->right != nullptr) {
            if (el->parent->right == el) {
                el->parent->right = el->right;
            }
            else if (el->parent->left == el) {
                el->parent->left = el->right;
            }
            el->right->parent = el->parent;
        }
        else if (el->left != nullptr) {
            if (el->parent->left == el) {
                el->parent->left = el->left;
            }
            else if (el->parent->right == el) {
                el->parent->right = el->left;
            }
            el->left->parent = el->parent;
        }
        delete el;
    }
    void pop3(node* el) {
        el->value = searchNext(el)->value;
        if (searchNext(el)->right == nullptr and searchNext(el)->left == nullptr) {
            pop1(searchNext(el));
        }
        else if (searchNext(el)->right != nullptr or searchNext(el)->left != nullptr) {
            pop2(searchNext(el));
        }
    }
    void pop(node* el) {
        if (el->left == nullptr and el->right == nullptr) {
            pop1(el);
        }
        else if ((el->left == nullptr and el->right != nullptr) or
                (el->left != nullptr and el->right == nullptr)) {
                    pop2(el);
        }
        else if (el->left != nullptr and el->right != nullptr) {
            pop3(el);
        }
    }

    node* exists(long long number) {
        node* temp = root;
        while (temp != nullptr and temp->value != number) {
            if (number < temp->value) {
                temp = temp->left;
            } 
            else if (number > temp->value) {
                temp = temp->right;
            }
        }
        if (temp == nullptr) {
            return nullptr;
        }
        else {
            return temp;
        }
    }
};

int main() {
    SearchTree ST1;
    for (long long i = 0; i < 100; i++) {
        string command; long long number;
        cin >> command >> number;
        if (command == "insert") {
            if (ST1.exists(number) != nullptr) {
                continue;
            }
            ST1.insert(number);
        }
        else if (command == "delete") {
            if (ST1.exists(number) == nullptr) {
                cout << "none" << "\n";
                continue;
            }
            ST1.pop(ST1.exists(number));
        }
        else if (command == "exists") {
            if (ST1.exists(number) != nullptr) {
                cout << "true" << "\n";
            }
            else {
                cout << "false" << "\n";
            }
        }
        else if (command == "next") {
            if (ST1.next(number) == nullptr) {
                cout << "none" << "\n";
                continue;
            }
            cout << ST1.next(number)->value << "\n";
        }
        else if (command == "prev") {
            if (ST1.prev(number) == nullptr) {
                cout << "none" << "\n";
                continue;
            }
            cout << ST1.prev(number)->value << "\n";
        }
    }
}