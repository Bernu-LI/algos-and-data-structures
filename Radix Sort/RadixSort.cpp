#include <iostream>
#include <cmath>

using namespace std;

void countingSort(int a[], int n, int k, int d) {
    int auxiliary_a[k];
    for (int i = 0; i < k; i++) {
        auxiliary_a[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        auxiliary_a[a[i] % (int)pow(10, d) / (int)pow(10, d - 1)]++;
    }
    for (int i = 1; i < k; i++) {
        auxiliary_a[i] += auxiliary_a[i - 1];
    }
    int result[n];
    for (int i = n - 1; i >= 0; i--) {
        result[auxiliary_a[a[i] % (int)pow(10, d) / (int)pow(10, d - 1)] - 1] = a[i];
        auxiliary_a[a[i] % (int)pow(10, d) / (int)pow(10, d - 1)]--;
    }
    for (int i = 0; i < n; i++) {
        a[i] = result[i];
    }
}

void radixSort(int a[], int n, int k, int r) {
    for (int d = 1; d <= r; d++) {
        countingSort(a, n, k, d);
    }
}

int main() {
    int array[] = {329, 457, 657, 839, 456, 720, 355};
    radixSort(array, 7, 10, 3);
    for (int i = 0; i < 7; i++) {
        cout << array[i] << " ";
    }
    return 0;
}

