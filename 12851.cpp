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

const int MAX = 1e5 + 1;

int N, M;
int minSec = 0;
int cnt = 0;
bool visited[MAX];

void bfs() {
	queue<pair<int, int>> q;	// 위치, 시간
	q.push({ N, 0 });
	visited[N] = true;

	while (!q.empty()) {
		int curX = q.front().first;
		int curSec = q.front().second;
		q.pop();

		visited[curX] = true;

		if (minSec && minSec == curSec && curX == M) {
			cnt++;

			continue;
		}

		if (!minSec && curX == M) {
			minSec = curSec;

			cnt++;
		}

		if (curX + 1 < MAX && !visited[curX + 1])
			q.push({ curX + 1, curSec + 1 });
		if (curX - 1 >= 0 && !visited[curX - 1])
			q.push({ curX - 1, curSec + 1 });
		if (curX * 2 < MAX && !visited[curX * 2])
			q.push({ curX * 2, curSec + 1 });
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	bfs();

	cout << minSec << "\n" << cnt;

	return 0;
}
