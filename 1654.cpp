#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 1000000;

int k, n;
long long low, high;
vector<int> line;

void input() {
	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		int temp;
		cin >> temp;

		line.push_back(temp);
	}
	sort(line.begin(), line.end());

	low = 1;
	high = line[k - 1];
}

bool check(long long mid) {
	long long num = 0;

	for (int i = 0; i < k; i++)
		num += line[i] / mid;

	if (num >= n) return true;
	return false;
}

long long binarySearch(long long start, long long end) {
	long long result = 0;

	while (start <= end) {
		long long mid = (start + end) / 2;

		if (check(mid)) {
			start = mid + 1;
			result = max(result, mid);
		}
		else end = mid - 1;
	}
	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << binarySearch(low, high);

	return 0;
}
