#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Type {
    int x, y;
};

struct num {
    int s;
    int i;
};

void Nhap2(Type* a, int n) {
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        cin >> a[i].x >> a[i].y;
    }
}

void Nhapa(num* a, int n) {
    for (int k = 0; k < n; k++) {
        cin >> a[k].s;
        a[k].i = k;
    }
}

int BinaryS(num* a, int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid].s == x) {
            return mid;
        }
        if (a[mid].s < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int findpos1(num* a, int n, int x) {
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (a[i].s == x) {
            if (a[i].i < min) {
                min = a[i].i;
            }
        }
    }
    return (min == INT_MAX) ? -1 : min;
}

int findpos2(num* a, int n, int x) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i].s == x) {
            if (a[i].i > max) {
                max = a[i].i;
            }
        }
    }
    return (max == INT_MIN) ? -1 : max;
}

int main() {
    int n, q;
    cin >> n >> q;
    num* a = new num[n];
    Type* b = new Type[q];

    Nhapa(a, n);
    Nhap2(b, q);

    sort(a, a + n, [](const num& a, const num& b) {
        return a.s < b.s;
        });

    int pos1, pos2;
    for (int i = 0; i < q; i++) {
        if (b[i].x == 1) {
            pos1 = findpos1(a, n, b[i].y);
            if (pos1 != -1) {
                cout << pos1 + 1 << endl;
            }
            else {
                cout << pos1 << endl;
            }
        }
        if (b[i].x == 2) {
            pos2 = findpos2(a, n, b[i].y);
            if (pos2 != -1) {
                cout << pos2 + 1 << endl;
            }
            else {
                cout << pos2 << endl;
            }
        }
    }

    delete[] a;
    delete[] b;
    return 0;
}
