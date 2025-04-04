#include <iostream>

using namespace std;

int binarySearch(int a[], int n, int x) {
    int l = -1;
    int r = n;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (a[mid] < x) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    if (r < n and a[r] == x) {
        return r;
    }
    else {
        return -1;
    }
}

int main() {
    int array[] = {1, 3, 4, 6, 7, 8, 10, 13, 14, 18, 19, 21, 24, 37, 40, 45, 71};
    cout << binarySearch(array, 17, 7);
    return 0;
}