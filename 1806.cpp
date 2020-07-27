#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 100000;

int n, s;
vector<int> list(MAX);
int cnt = MAX;
bool isPossible = false;

void input() {
	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> list[i];
}

void func() {
	int high, low, sum;
	high = low = sum = 0;

	while (true) {
		if (sum >= s)
			sum -= list[low++];
		else if (high >= n + 1) break;
		else if (sum < s)
			sum += list[high++];

		if (sum >= s) {
			isPossible = true;

			cnt = min(cnt, high - low);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func();

	if (isPossible) cout << cnt;
	else cout << "0";

	return 0;
}
