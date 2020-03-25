#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long x, y;	// x = 게임 횟수 y = 이긴 게임
vector<int> result;

bool check(long long num) {
	if (y * 100 / x == (y + num) * 100 / (x + num))
		return false;
	result.push_back(num);
	return true;
}

void binarySearch(long long start, long long end) {
	while (start <= end) {
		long long mid = (start + end) / 2;

		if (check(mid)) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y;

	binarySearch(1, x);

	if (result.empty())
		cout << "-1";
	else {
		sort(result.begin(), result.end());

		cout << result[0];
	}

	return 0;
}
