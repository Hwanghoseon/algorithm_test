#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> tree;

bool desc(int a, int b) {
	return a > b;
}

void input() {
	cin >> n;

	tree.resize(n);

	for (int i = 0; i < n; i++)
		cin >> tree[i];

	sort(tree.begin(), tree.end(), desc);
}

int func() {
	int result = 0;

	for (int i = 0; i < n; i++)
		result = max(result, tree[i] + i + 1);

	result++;

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << func();

	return 0;
}
