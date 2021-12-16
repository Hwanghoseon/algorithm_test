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

const int MAX = 1500 + 1;

queue<pair<pair<int, int>, int>> q;
int A, B, C;
bool visited[MAX][MAX];

int bfs() {
	q.push({ {A, B}, C });
	visited[A][B] = true;

	while (!q.empty()) {
		int curA = q.front().first.first;
		int curB = q.front().first.second;
		int curC = q.front().second;
		q.pop();

		if (curA == curB && curB == curC) return 1;

		int nextA, nextB, nextC;

		// 1, 2
		nextA = abs(curA - curB);
		nextB = 2 * min(curA, curB);

		if (!visited[nextA][nextB] && curA != curB) {
			visited[nextA][nextB] = true;

			q.push({ {nextA, nextB}, curC });
		}

		// 1, 3
		nextA = abs(curA - curC);
		nextC = 2 * min(curA, curC);

		if (!visited[nextA][curB] && curA != curC) {
			visited[nextA][curB] = true;

			q.push({ {nextA, curB}, nextC });
		}

		// 2, 3
		nextB = abs(curB - curC);
		nextC = 2 * min(curB, curC);

		if (!visited[curA][nextB] && curB != curC) {
			visited[curA][nextB] = true;

			q.push({ {curA, nextB}, nextC });
		}
	}

	return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B >> C;

	if ((A + B + C) % 3) cout << 0;
	else
		cout << bfs();

	return 0;
}
