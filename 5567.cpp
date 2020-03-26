#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 500 + 1;

int n, m;
vector<int> list[MAX];
bool visit[MAX];

void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;

		list[from].push_back(to);
		list[to].push_back(from);
	}

	for (int i = 0; i < n; i++)
		sort(list[i].begin(), list[i].end());
}

int bfs(int x) {
	int cnt = 2;
	int personCnt = 0;

	queue<int> arr;
	arr.push(x);
	visit[x] = true;

	while (!arr.empty() && cnt--) {
		int sz = arr.size();

		for (int i = 0; i < sz; i++) {
			int curPerson = arr.front();

			arr.pop();

			for (int j = 0; j < list[curPerson].size(); j++) {
				int nextPerson = list[curPerson][j];

				if (!visit[nextPerson]) {
					visit[nextPerson] = true;
					arr.push(nextPerson);
					personCnt++;
				}
			}
		}
	}

	return personCnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << bfs(1);

	return 0;
}
