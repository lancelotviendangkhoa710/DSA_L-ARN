

#include <iostream>
#include <vector>
using namespace std;
void insertion_sort(vector<int> &a)
{
	int n = a.size();
	int current;
	int j = 0;
	for (int i = 1; i < n; i++)
	{
		current = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > current)
		{
			a[j + 1] = a[j];//chèn vị trí nếu a[i] <a[j]
			j--;//check xem ở phía trước có phần tử nào nhỏ nữa không

		}
		a[j + 1] = current; //đặt current về vị trí đúng
	}
}
int main()
{
	int n; cin >> n;
	vector<int> a (n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	insertion_sort(a);
	for (int i = 0; i < n; i++)
	{
		cout<< a[i]<<" ";
	}
}

