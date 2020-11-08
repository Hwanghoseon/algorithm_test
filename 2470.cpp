#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>

using namespace std;

const int MAX = 1000000000;

int N;
vector<int> list;
pair<int, int> result;

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
	sum = INT_MAX;
	
	int before = MAX * 2;

	while (low < high) {
		int sum = list[low] + list[high];

		if (abs(before) > abs(sum)) {
			result = { list[low], list[high] };

			before = sum;
		}

		if (sum == 0) {
			low++;
			high--;
		}
		else if (sum > 0)
			high--;
		else
			low++;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func();

	cout << result.first << " " << result.second;

	return 0;
}
