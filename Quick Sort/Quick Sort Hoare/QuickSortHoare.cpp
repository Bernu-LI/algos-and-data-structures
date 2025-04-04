#include <iostream>
#include <algorithm>

using namespace std;

void quickSort(int a[], int l, int r) {
    int i = l;
    int j = r;
    int pivot = a[(l + r) / 2];
    while (i <= j) {
        while (a[i] < pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j) {
        quickSort(a, l, j);
    }
    if (i < r) {
        quickSort(a, i, r);
    }
}

int main() {
    int array[] = {6, 7, 2, 5, 9, 1, 3, 8};
    quickSort(array, 0, 7);
    for (int i = 0; i < 8; i++) {
        cout << array[i] << " ";
    }
    return 0;
}