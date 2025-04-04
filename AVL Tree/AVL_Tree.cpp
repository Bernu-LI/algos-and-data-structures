#include <iostream>

using namespace std;

struct node {
    node(int v): value(v), height(1) {}
    int value;
    int height;
    node* left = nullptr;
    node* right = nullptr;
};

int getHeight(node* el) {
    return el ? el->height : 0;
}

int balanceFactor(node* el) {
    return getHeight(el->right) - getHeight(el->left);
}

void fixHeight(node* el) {
    int lh = getHeight(el->left);
    int rh = getHeight(el->right);
    el->height = (lh > rh ? lh : rh) + 1;
}

struct AVL_Tree {

    node* root = nullptr;

    node* leftRotate(node* el) {
        node* p = el->right;
        el->right = p->left;
        p->left = el;
        fixHeight(el);
        fixHeight(p);
        return p;
    }

    node* rightRotate(node* el) {
        node* p = el->left;
        el->left = p->right;
        p->right = el;
        fixHeight(el);
        fixHeight(p);
        return p;
    }

    node* balance(node* el) {
        fixHeight(el);

        if (balanceFactor(el) == 2) {
            if (balanceFactor(el->right) < 0) {
                el->right = rightRotate(el->left);
            }
            return leftRotate(el);
        }
        else if (balanceFactor(el) == -2) {
            if (balanceFactor(el->left) > 0) {
                el->left = leftRotate(el->right);
            }
            return rightRotate(el);
        }

        return el;
    }

    node* insert(node* temp, int number) {
        if (temp == nullptr) {
            return new node(number);
        }
        if (number < temp->value) {
            temp->left = insert(temp->left, number);
        }
        else if (number > temp->value) {
            temp->right = insert(temp->right, number);
        }
        return balance(temp);
    }
};