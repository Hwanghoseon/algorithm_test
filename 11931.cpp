#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 1000000;
vector<int> list;

int desc(int a, int b) {
	return a > b;
}

void input(int n) {
	list.resize(n);

	for (int i = 0; i < n; i++)
		cin >> list[i];

	sort(list.begin(), list.end(), desc);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> num;

	input(num);

	for (int i = 0; i < num; i++)
		cout << list[i] << "\n";

	return 0;
}
