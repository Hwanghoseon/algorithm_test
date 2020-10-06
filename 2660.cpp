#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 50 + 1;
const int INF = 1e3;

int N;
int dist[MAX][MAX];
int nxt[MAX][MAX];
vector<pair<int, int>> result;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
		fill(dist[i], dist[i] + N + 1, INF);

	while (true) {
		int from, to;
		cin >> from >> to;

		if (from == -1 && to == -1) break;

		dist[from][to] = min(dist[from][to], 1);
		nxt[from][to] = to;

		dist[to][from] = min(dist[to][from], 1);
		nxt[to][from] = from;
	}

	for (int i = 1; i <= N; i++)
		dist[i][i] = 0;

	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];

					nxt[i][j] = nxt[i][k];
				}

	int maxPoint = 0;
	for (int i = 1; i <= N; i++) {
		int point = 0;

		for (int j = 1; j <= N; j++)
			point = max(point, dist[i][j]);

		result.push_back(make_pair(point, i));

		maxPoint = max(maxPoint, point);
	}

	sort(result.begin(), result.end());

	int cnt = 0;
	int temp = result[0].first;
	for (int i = 0; i < N; i++) {
		if (temp == result[i].first) cnt++;
		else break;
	}

	cout << result[0].first << " " << cnt << "\n";

	for (int i = 0; i < cnt; i++)
		cout << result[i].second << " ";

	return 0;
}
