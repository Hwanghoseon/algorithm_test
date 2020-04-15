#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 100 + 1;

int n, m;
int graph[MAX][MAX];

void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		if (!graph[from][to])
			graph[from][to] = cost;
		else	// 이미 경로가 존재할 경우
			graph[from][to] = min(graph[from][to], cost);
	}
}

void floyd() {
	// via경로를 이용할 경우가 더 빠른 경우
	for (int via = 1; via <= n; via++) {
		for (int from = 1; from <= n; from++) {
			if (!graph[from][via]) continue;

			for (int to = 1; to <= n; to++) {
				if (!graph[via][to] || from == to) continue;

				if (!graph[from][to] || graph[from][to] > graph[from][via] + graph[via][to])
					graph[from][to] = graph[from][via] + graph[via][to];
			}
		}
	}
}

void printGraph() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << graph[i][j] << " ";
		cout << "\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	floyd();

	printGraph();

	return 0;
}
