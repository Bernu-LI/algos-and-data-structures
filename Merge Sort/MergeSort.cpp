#include <iostream>

using namespace std;

void merge(int a[], int l, int mid, int r) {
    int it1 = 0;
    int it2 = 0;
    int result[r - l];
    while ( (l + it1 < mid) and (mid + it2 < r) ) {
        if (a[l + it1] <= a[mid + it2]) {
            result[it1 + it2] = a[l + it1];
            it1++;
        }
        else {
            result[it1 + it2] = a[mid + it2];
            it2++;
        }
    }
    while (l + it1 < mid) {
        result[it1 + it2] = a[l + it1];
        it1++;
    }
    while (mid + it2 < r) {
        result[it1 + it2] = a[mid + it2];
        it2++;
    }
    for (int i = 0; i < (r - l); i++) {
        a[l + i] = result[i];
    }
}

void mergeSort(int a[], int l, int r) {
    if (l + 1 == r) {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid, r);
    merge(a, l, mid, r);
}

int main() {
    int array[] = {72, 4, 54, 10, 41, 27, 54, 3, 0};
    mergeSort(array, 0, 9);
    for (int i = 0; i < 9; i++) {
        cout << array[i] << " ";
    }
    return 0;
}