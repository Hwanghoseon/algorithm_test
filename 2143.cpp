#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const long long MAX = 1000;

vector<long long> arrA;
vector<long long> arrB;
vector<long long> listA;
vector<long long> listB;
long long t, n, m;

void input() {
	cin >> t;

	cin >> n;

	arrA.resize(n);
	for (long long i = 0; i < n; i++)
		cin >> arrA[i];

	cin >> m;

	arrB.resize(m);
	for (long long i = 0; i < m; i++)
		cin >> arrB[i];
}

long long lowBoundary(long long low, long long high, long long target) {
	while (high > low) {
		long long mid = (high + low) / 2;

		if (listB[mid] >= target)
			high = mid;
		else low = mid + 1;
	}

	return low;
}

long long highBoundary(long long low, long long high, long long target) {
	while (high > low) {
		long long mid = (high + low) / 2;

		if (listB[mid] <= target)
			low = mid + 1;
		else
			high = mid;
	}

	return low;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	// 배열 A기준
	for (long long i = 0; i < n; i++) {
		long long arrA_sum = 0;
		for (long long j = i; j < n; j++) {
			arrA_sum += arrA[j];

			listA.push_back(arrA_sum);
		}
	}

	sort(listA.begin(), listA.end());

	for (long long i = 0; i < m; i++) {
		long long arrB_sum = 0;
		for (long long j = i; j < m; j++) {
			arrB_sum += arrB[j];

			listB.push_back(arrB_sum);
		}
	}

	sort(listB.begin(), listB.end());

	long long result = 0;
	for (long long i = 0; i < listA.size(); i++) {
		int low = lowBoundary(0, listB.size(), t - listA[i]);
		int high = highBoundary(0, listB.size(), t - listA[i]);

		result += (high - low);
	}

	cout << result;

	return 0;
}
