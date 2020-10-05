#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAX = 26 + 26;
const int INF = 1e5;

int N;
int dist[MAX][MAX];
int nxt[MAX][MAX];
string temp;
int cnt = 0;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	getline(cin, temp);
	N = stoi(temp);

	for (int i = 0; i < MAX; i++)
		fill(dist[i], dist[i] + MAX, INF);

	while (N--) {
		getline(cin, temp);

		int from, to;
		from = temp[0] < 'a' ? temp[0] - 'A' : temp[0] - 'a' + 26;
		to = temp[5] < 'a' ? temp[5] - 'A' : temp[5] - 'a' + 26;

		dist[from][to] = min(dist[from][to], 1);
		nxt[from][to] = to;
	}

	for (int i = 0; i < MAX; i++)
		dist[i][i] = 0;

	for(int k = 0; k < MAX; k++)
		for(int i = 0; i < MAX; i++)
			for(int j = 0; j < MAX; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];

					nxt[i][j] = nxt[i][k];
				}

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++) {
			if (!dist[i][j] || dist[i][j] == INF) continue;

			cnt++;
		}

	cout << cnt << "\n";

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (!dist[i][j] || dist[i][j] == INF) continue;

			char x, y;
			x = i < 26 ? (char)(i + 'A') : (char)(i - 26 + 'a');
			y = j < 26 ? (char)(j + 'A') : (char)(j - 26 + 'a');

			cout << x << " => " << y << "\n";
		}
	}

	return 0;
}
