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
vector<pair<int, int>> list;	// num, idx
vector<int> result;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		list.push_back({ temp, i });
	}

	sort(list.begin(), list.end());
}

void solution() {
	result.resize(N);

	int cnt = 0;

	for (int i = 0; i < N; i++)
		result[list[i].second] = cnt++;

	for (int i = 0; i < N; i++)
		cout << result[i] << " ";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();

	return 0;
}
