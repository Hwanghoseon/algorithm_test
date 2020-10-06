#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 100 + 1;
const int INF = 1e5;

int N;
int dist[MAX][MAX];
int nxt[MAX][MAX];
int temp;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
		fill(dist[i], dist[i] + N + 1, INF);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> temp;

			if (temp) {
				dist[i][j] = min(dist[i][j], 1);

				nxt[i][j] = j;
			}
		}

	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];

					nxt[i][j] = nxt[i][k];
				}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!dist[i][j] || dist[i][j] == INF)
				cout << "0 ";
			else cout << "1 ";
		}

		cout << "\n";
	}

	return 0;
}
