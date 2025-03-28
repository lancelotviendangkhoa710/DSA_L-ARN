#include <iostream>
#include <vector>
using namespace std;

void Nhap(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void check(int* a, int n, int k, vector<string>& results) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == k) dem++;
    }

    if (dem == 1) {
        results.push_back("YES");
    }
    else {
        results.push_back("NO");
    }
}

int main() {
    int t;
    cin >> t;
    int i = 0;
    vector<string> results;
    while (i < t) {
        int n, k;
        cin >> n >> k;
        int* a = new int[n];
        Nhap(a, n);
        check(a, n, k, results);
        i++;
        delete[] a;
    }

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}
