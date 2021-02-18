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

using namespace std;

const int MAX = 1e6;
const int INF = 2e9 + 1;

int N, M;
vector<int> list;

bool desc(int a, int b) {
	return a > b;
}

void input() {
	cin >> N >> M;

	list.resize(N);

	for (int i = 0; i < N; i++)
		cin >> list[i];

	sort(list.begin(), list.end(), desc);
}

int solution() {
	int startIdx = 0;
	int endIdx = 0;

	int ans = INF;

	while (endIdx < N) {
		int result = list[startIdx] - list[endIdx];

		if (result > M) {
			startIdx++;

			ans = min(ans, result);
		}
		else if (result < M)
			endIdx++;
		else{
			startIdx++;
			endIdx++;

			ans = min(ans, result);
		}
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
