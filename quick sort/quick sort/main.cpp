#include <iostream>
#include <algorithm>
using namespace std;

int Partition(int* a, int left, int right)
{
    int pivot = a[right];
    int pos = left - 1;
    for (int i = left; i < right; i++)
    {
        if (a[i] < pivot)
        {
            pos++;
            swap(a[i], a[pos]);
        }
    }
    swap(a[pos + 1], a[right]);
    return pos + 1; 
}

void QS(int* a, int left, int right)
{
    if (left < right)
    {
        int pivotIndex = Partition(a, left, right);
        QS(a, left, pivotIndex - 1); 
        QS(a, pivotIndex + 1, right); 
    }
}

int main() {
    int n;
    cin >> n; // Input size of array
    int* a = new int[n];

    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Perform the QuickSort
    QS(a, 0, n - 1);

    // Output the sorted array
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    delete[] a; // Free memory
    return 0;
}
