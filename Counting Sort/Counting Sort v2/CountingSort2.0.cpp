#include <iostream>

using namespace std;

void countingSort(int a[], int n, int k) {
    int auxiliary_a[k];
    for (int i = 0; i < k; i++) {
        auxiliary_a[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        auxiliary_a[a[i]]++;
    }
    for (int i = 1; i < k; i++) {
        auxiliary_a[i] += auxiliary_a[i - 1];
    }
    int result[n];
    for (int i = n - 1; i >= 0; i--) {
        result[auxiliary_a[a[i]] - 1] = a[i];
        auxiliary_a[a[i]]--;
    }
    for (int i = 0; i < n; i++) {
        a[i] = result[i];
    }
}

int main() {
    int array[] = {3, 4, 1, 0, 5, 0, 3, 1, 3};
    countingSort(array, 9, 6);
    for (int i = 0; i < 9; i++) {
        cout << array[i] << " ";
    }
    return 0;
}