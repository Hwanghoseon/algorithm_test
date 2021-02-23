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

const int MAX = 200 + 1;
const int INF = 1e5;

int N, M;
int dist[MAX][MAX];
vector<int> list;

void input() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		fill(dist[i], dist[i] + N + 1, INF);

	for (int i = 1; i <= N; i++)	
		for (int j = 1; j <= N; j++) {
			int temp;
			cin >> temp;

			if (temp) dist[i][j] = temp;
		}
}

void func() {
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];

	for (int i = 1; i <= N; i++)
		dist[i][i] = 1;

	list.resize(M);
	bool isPossible = true;

	for (int i = 0; i < M; i++)
		cin >> list[i];

	for (int i = 0; i < M - 1; i++) {
		int from = list[i];
		int to = list[i + 1];

		if (dist[from][to] == INF) {
			isPossible = false;
			break;
		}
	}

	if (isPossible) cout << "YES\n";
	else cout << "NO\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func();

	return 0;
}
