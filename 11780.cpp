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

const int MAX = 100 + 1;
const int INF = 1e8;

int N, M;
int dist[MAX][MAX];
int nxt[MAX][MAX];

void input() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dist[i][j] = INF;

	for (int i = 0; i < M; i++) {
		int from, to, value;
		cin >> from >> to >> value;

		dist[from][to] = min(dist[from][to], value);
		nxt[from][to] = to;
	}

	for (int i = 1; i <= N; i++)
		dist[i][i] = 0;
}

void floyd_warshall() {
	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];

					nxt[i][j] = nxt[i][k];
				}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] == INF) cout << "0 ";
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j || dist[i][j] == INF) {
				cout << "0\n";

				continue;
			}

			vector<int> path;
			int st = i;

			while (st != j) {
				path.push_back(st);

				st = nxt[st][j];
			}
			path.push_back(st);

			cout << path.size() << " ";

			for (int k = 0; k < path.size(); k++)
				cout << path[k] << " ";

			cout << "\n";
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	floyd_warshall();

	return 0;
}
