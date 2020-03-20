#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 1000000;

int n;
long long m;
long long result;
long long low, high;
vector<long long> arr;

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());

	low = 1;
	high = arr[n - 1];	// 제일 높은 나무의 높이
}

bool check(long long mid) {
	long long len = 0;

	for (int i = 0; i < n; i++)
		if (arr[i] > mid)
			len += arr[i] - mid;

	if (len >= m)
		return true;
	return false;
}

// 여기서는 배열의 중간값을 이분탐색하는 것이 아니라
// 1부터 최대값 사이의 모든 값을 생각해야하기 때문에
// 1부터 최대값 사이를 범위로 이분탐색을 한다.

void binarySearch(int start, int end) {
	while (start <= end) {
		long long mid = (start + end) / 2;

		if (check(mid)) {
			result = max(result, mid);
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	binarySearch(low, high);

	cout << result;

	return 0;
}
