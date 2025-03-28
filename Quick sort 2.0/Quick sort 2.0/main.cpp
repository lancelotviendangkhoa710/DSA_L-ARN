#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int partition(vector < int > a, int left, int right) {
	int pivot = a[right];
	int i = left - 1;
		for (int j = left; j < right; j++) {
			if (a[j] <= pivot)
			{
				i++;
				swap(a[i], a[j]);

			}
		}
		swap(a[i + 1], a[right]);//đặt pivot về giữa
		return i + 1; //index pivot
 }
 void Quick(vector <int> a, int left, int right)
{
	 if (left < right)
	 {
		 int ispivot = partition(a, left, right);
		 Quick(a, left, ispivot - 1);
		 Quick(a, ispivot + 1, right);

	 }

}
int main() {
	int n; cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	Quick(a, 0, a.size());
	for (int i = 0; i < n; i++)
	{
		cout<< a[i]<<" ";
	}
	return 0;
}