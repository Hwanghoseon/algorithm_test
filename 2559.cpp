#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, K;
vector<int> list;
int result;

void input() {
	cin >> N >> K;

	list.resize(N + 1);

	for (int i = 0; i < N; i++)
		cin >> list[i];
}

void func() {
	int high, low, sum;
	low = sum = 0;
	high = K;
	
	for (int i = 0; i < K; i++)
		sum += list[i];

	result = sum;

	while (high < N) {
		sum -= list[low++];
		sum += list[high++];

		result = max(result, sum);
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
