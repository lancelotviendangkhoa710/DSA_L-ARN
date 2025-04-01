#include <iostream>
#include <queue>
using namespace std;
int main() {
	queue <int> q;
	int n; cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		q.push(a[i]);

	}
	
	while (!q.empty()) {
		cout << q.front()<<" ";
		q.pop();
	}
	return 0;

}