#include <iostream>

using namespace std;

int partition(int a[], int l, int r) {
    int i = l - 1;
    int j = l;
    int pivot = a[r - 1];
    for (; j < r; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i + 1], a[r - 1]);
    return i + 1;
}

void quickSort(int a[], int l, int r) {
    if (l < r) {
        int q = partition(a, l, r);
        quickSort(a, l, q);
        quickSort(a, q + 1, r);
    }
}

int main() {
    int array[] = {10, 2, 8, 15, 1, 81, 9};
    quickSort(array, 0, 7);
    for (int i = 0; i < 7; i++) {
        cout << array[i] << " ";
    }
    return 0;
}