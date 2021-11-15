#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cstdio>
#include<climits>

using namespace std;

const int MAX = 1299709 + 1;

bool list[MAX];
vector<int> prime;

void func() {
	for (long long i = 2; i < MAX; i++)
		for (long long j = i * i; j < MAX; j += i) 
			list[j] = true;

	for (int i = 2; i < MAX; i++)
		if (!list[i])
			prime.push_back(i);
}

int binarySearch(int target) {
	int low = 0;
	int high = prime.size() - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (prime[mid] <= target)
			low = mid + 1;
		else high = mid - 1;
	}

	return low;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	func();

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		if (!list[N]) {
			cout << "0\n";

			continue;
		}

		int idx = binarySearch(N);
		cout << prime[idx] - prime[idx - 1] << "\n";
	}

	return 0;
}
