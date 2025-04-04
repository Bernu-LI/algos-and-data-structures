#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct heap {
    heap(vector <int>& v_): v(v_) {
        for (int i = v.size() - 1; i >= 0; i--) {
            sift_down(i, v.size());
        }
    }

    vector <int> v;

    void sift_up(int i) {
        while (i > 0 and v[i] < v[(i - 1) / 2]) {
            swap(v[i], v[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void sift_down(int i, int size) {
        while (true) {
            int j = i;
            if (i * 2 + 1 < size and v[j] > v[2 * i + 1]) {
                j = 2 * i + 1;
            }
            if (i * 2 + 2 < size and v[j] > v[2 * i + 2]) {
                j = 2 * i + 2;
            }
            if (i == j) {
                break;
            }
            else {
                swap(v[i], v[j]);
                i = j;
            }
        }
    }

    void push(int number) {
        v.push_back(number);
        sift_up(v.size() - 1);
    }

    int pop() {
        if (v.size() == 0) {
            cout << "Nothing to remove" << "\n";
            return -1;
        }
        else {
            int temp = v[0];
            swap(v[0], v[v.size() - 1]);
            v.pop_back();
            sift_down(0, v.size());
            return temp;
        }
    }

    void heapSort() {
        for (int i = v.size() - 1; i > 0; i--) {
            swap(v[0], v[i]);
            sift_down(0, i);
        }
    }

    void print() {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
    }
};

int main() {
    vector <int> array = {2, 5, 15, 4, 20, 25, 8, 6, 9, 69, 18, 7, 17, 3};
    heap h1(array);
    h1.print();
    cout << "\n";
    h1.pop();
    h1.print();
    cout << "\n";
    h1.push(21);
    h1.print();
    cout << "\n";
    h1.push(1);
    h1.print();
    cout << "\n";
    h1.pop();
    h1.print();
    cout << "\n";
    h1.heapSort();
    h1.print();
    return 0;
}