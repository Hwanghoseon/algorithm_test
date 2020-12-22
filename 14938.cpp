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

const int MAX = 100 + 1;

int N, M, R;
int item[MAX];
vector<pair<int, int>> graph[MAX];	// value, to
int list[MAX][MAX];

void input() {
	cin >> N >> M >> R;

	for (int i = 1; i <= N; i++)
		cin >> item[i];

	/*for (int i = 0; i < R; i++) {
		int from, to, value;
		cin >> from >> to >> value;

		graph[from].push_back(make_pair(value, to));
		graph[to].push_back(make_pair(value, from));
	}*/

	for (int i = 1; i <= N; i++) {
		fill(list[i], list[i] + N + 1, MAX);
	}

	for (int i = 0; i < R; i++) {
		int from, to, value;
		cin >> from >> to >> value;

		list[from][to] = value;
		list[to][from] = value;
	}
}

int func() {
	// 플로이드-와샬
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (list[i][j] > list[i][k] + list[k][j])
					list[i][j] = list[i][k] + list[k][j];
			}
		}
	}

	for (int i = 1; i <= N; i++)
		list[i][i] = 0;

	int result = 0;

	// 거리 계산
	for (int i = 1; i <= N; i++) {
		int sum = 0;

		for (int j = 1; j <= N; j++) {
			if (list[i][j] <= M) sum += item[j];
		}

		result = max(result, sum);
	}

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << func();

	return 0;
}

// 플로이드 와샬?
// 100 * 100 * 100
