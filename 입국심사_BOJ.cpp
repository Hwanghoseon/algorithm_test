#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<cstdio>
#include<climits>

using namespace std;

int N, M;
vector<long long> list;

void input() {
	cin >> N >> M;

	list.resize(N);

	for (int i = 0; i < N; i++)
		cin >> list[i];

	sort(list.begin(), list.end());
}

long long binarySearch() {
	long long low = 0, high = list[N - 1] * M;
	long long ans = list[N - 1] * M;

	while (low <= high) {
		long long sec = 0;
		long long mid = (low + high) / 2;

		for (int i = 0; i < N; i++)
			sec += mid / list[i];

		if (sec >= M) {
			ans = min(ans, mid);

			high = mid - 1;
		}
		else low = mid + 1;
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << binarySearch();

	return 0;
}
