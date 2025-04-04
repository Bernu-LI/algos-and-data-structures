#include <iostream>

using namespace std;

void binarySearch(int a[], int n, int x) {
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
    int l_b;
    if (r < n and a[r] == x) {
        l_b = r;
    }
    else {
        cout << -1;
        return;
    }
    l = -1;
    r = n;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (a[mid] <= x) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    int r_b = l;
    cout << r_b - l_b + 1 << "\n";
    cout << l_b;
}

int main() {
    int array[] = {8, 22, 22, 78, 89, 100};
    binarySearch(array, 6, 22);
    return 0;
}