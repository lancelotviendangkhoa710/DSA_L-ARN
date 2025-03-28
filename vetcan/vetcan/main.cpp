#include <iostream>
using namespace std;

int captichlonnhat(int* a, int n) {
    int val = -1e9;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] * a[j] > val) {
                val = a[i] * a[j];
            }
        }
    }
    return val;
}

int main() {
    int n, res;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    res = captichlonnhat(a, n);
    cout << res;
    delete[] a;
    return 0;
}
