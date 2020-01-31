#include<iostream>
#include<queue>

using namespace std;

const int MAX = 100000 + 1;

bool visit[MAX];

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, 0 });
	visit[x] = true;

	while (!q.empty()) {
		int curLoc = q.front().first;
		int curSec = q.front().second;

		q.pop();

		//동생의 위치에 도달했을 때
		if (curLoc == y)
			return curSec;

		// X + 1 이동할 때
		if (curLoc + 1 < MAX && !visit[curLoc + 1]) {
			q.push({ curLoc + 1, curSec + 1 });
			visit[curLoc + 1] = true;
		}
		
		// X - 1 이동할 때
		if (curLoc - 1 >= 0 && !visit[curLoc - 1]) {
			q.push({ curLoc - 1, curSec + 1 });
			visit[curLoc - 1] = true;
		}

		// 2 * X 이동할 때
		if (curLoc * 2 < MAX && !visit[curLoc * 2]) {
			q.push({ curLoc * 2, curSec + 1 });
			visit[curLoc * 2] = true;
		}
	}
}

int main(void) {
	int N, M;
	cin >> N >> M;

	cout << bfs(N, M);

	return 0;
}
