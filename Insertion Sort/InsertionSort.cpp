#include <iostream>

using namespace std;

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while(j >= 0 and a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    int array[] = {4, 7, 1, 3, 2, 5, 2, 8, 11};
    insertionSort(array, 9);
    for (int i = 0; i < 9; i++) {
        cout << array[i] << " ";
    }
    return 0;
}