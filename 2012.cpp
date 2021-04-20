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

const int MAX = 500000;

int N;
vector<int> list;

void input() {
	cin >> N;

	list.resize(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> list[i];

	sort(list.begin(), list.end());
}

long long solution() {
	long long ans = 0;

	for (int i = 1; i <= N; i++)
		ans += abs(list[i] - i);

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
