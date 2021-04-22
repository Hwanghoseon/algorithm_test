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

const long long MAX = 1e7 + 1;

long long A, B;
long long list[MAX];
vector<long long> candidate;

void primeNumberCheck() {
	list[1] = true;

	for (long long i = 2; i < MAX; i++) {
		for (long long j = i * i; j < MAX; j += i) {
			list[j] = true;
		}
	}

	for (int i = 2; i < MAX; i++)
		if (!list[i])
			candidate.push_back(i);
}

long long solution() {
	long long cnt = 0;

	for (int i = 0; i < candidate.size(); i++) {
		long long num = candidate[i];

		while (candidate[i] <= B / num) {
			if (candidate[i] * num >= A)
				cnt++;

			num *= candidate[i];
		}
	}

	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	primeNumberCheck();

	cin >> A >> B;

	cout << solution();

	return 0;
}
