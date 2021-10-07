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

const int MAX = 1e4;

int N;
vector<int> list;

void input() {
	list.clear();

	list.resize(N);

	for (int i = 0; i < N; i++)
		cin >> list[i];
}

int solution() {
	int ans = 0;

	sort(list.begin(), list.end());

	for (int i = 0; i < N - 2; i++)
		ans = max(ans, list[i + 2] - list[i]);

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		cin >> N;

		input();

		cout << solution() << "\n";
	}

	return 0;
}
