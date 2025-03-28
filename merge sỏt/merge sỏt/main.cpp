#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++) 
    {
        leftArr[i] = a[left + i];
    }
    for (int i = 0; i < n2; i++) 
    {
        rightArr[i] = a[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            a[k] = leftArr[i];
            i++;
        }
        else {
            a[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = rightArr[j];
        j++;
        k++;
    }
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void mergeSort(vector<int>& a, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}
void print_arr(vector<int>&a) {
    for (int& i : a) cout << i << " ";
    cout << "\n";
}
void Swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void bubble_sort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) { 
            if (a[j] > a[j + 1]) {
                Swap(a[j], a[j + 1]);
                print_arr(a);
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    /*for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }*/
    cout << endl;
    
   // mergeSort(a, 0, a.size() - 1);

    bubble_sort(a);
    return 0;
}
