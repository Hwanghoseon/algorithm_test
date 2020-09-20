#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> list(n);

	for (int i = 0; i < n; i++)
		cin >> list[i];

	sort(list.begin(), list.end());

	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += (n - i) * list[i];

	cout << sum;

	return 0;
}
