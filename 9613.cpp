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

int N;
vector<int> list;

void input() {
	cin >> N;

	list.clear();

	list.resize(N);

	for (int i = 0; i < N; i++)
		cin >> list[i];
}

int gcd(int a, int b) {
	int c;

	while (b) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

long long solution() {
	long long ans = 0;

	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++)
			ans += gcd(list[i], list[j]);

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		input();

		cout << solution() << "\n";
	}

	return 0;
}
