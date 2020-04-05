#include<iostream>
#include<queue>

using namespace std;

const int MAX = 1000000 + 1;

int F, S, G, U, D;
int visit[MAX];

int bfs() {
	queue<int> q;
	q.push(S);
	visit[S] = 1;

	int cnt = 0;
	while (!q.empty()) {
		int sz = q.size();
		
		cnt++;
		for (int k = 0; k < sz; k++) {
			int cur = q.front();
			q.pop();

			if (cur == G)
				return cnt - 1;

			int next[2] = { cur + U, cur - D };

			for (int i = 0; i < 2; i++) {
				if (1 <= next[i] && next[i] <= F) {
					if (!visit[next[i]]) {
						q.push(next[i]);
						visit[next[i]] = true;
					}
				}
			}
		}
		
	}

	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> F >> S >> G >> U >> D;

	int result = bfs();

	if (result == -1)
		cout << "use the stairs";
	else cout << result;

	return 0;
}
