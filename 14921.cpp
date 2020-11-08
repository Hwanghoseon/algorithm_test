#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int N;
vector<int> list;
int result = 1e9;

void input() {
	cin >> N;

	list.resize(N);

	for (int i = 0; i < N; i++)
		cin >> list[i];

	sort(list.begin(), list.end());
}

void func() {
	int high, low, sum;
	low = 0;
	high = N - 1;

	while (low < high) {
		sum = list[low] + list[high];

		if (sum == 0) {
			result = 0;
			return;
		}
		else if (sum > 0)
			high--;
		else low++;

		result = abs(result) < abs(sum) ? result : sum;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func();

	cout << result;

	return 0;
}
