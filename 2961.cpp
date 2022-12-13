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

const int MAX = 1e9 + 1;

int N;
int result = MAX;
vector<pair<int, int>> list;

void input() {
	cin >> N;

	list.resize(N);

	for (int i = 0; i < N; i++)
		cin >> list[i].first >> list[i].second;
}

void backtracking(int idx, int cnt, int num, int sValue, int bValue) {
	if (cnt == num) {
		result = min(result, abs(sValue - bValue));

		return;
	}

	if (idx == list.size()) return;

	// 재료를 사용할 경우
	backtracking(idx + 1, cnt + 1, num, sValue * list[idx].first, bValue + list[idx].second);

	// 재료를 사용하지 않을 경우
	backtracking(idx + 1, cnt, num, sValue, bValue);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	for (int i = 1; i <= N; i++)
		backtracking(0, 0, i, 1, 0);

	cout << result;

	return 0;
}
