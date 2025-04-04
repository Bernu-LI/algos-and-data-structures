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
    int position = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < auxiliary_a[i]; j++) {
            a[position] = i;
            position++;
        }
    }
}

int main() {
    int array[] = {4, 3, 4, 2, 0, 4, 3, 3, 4};
    countingSort(array, 9, 5);
    for (int i = 0; i < 9; i++) {
        cout << array[i] << " ";
    }
    return 0;
}