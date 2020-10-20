#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 100 + 1;

int N, M;
vector<int> graph[MAX];
int firstPerson, secondPerson;
bool visited[MAX];

void input() {
	cin >> N;
	cin >> firstPerson >> secondPerson;

	cin >> M;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;

		graph[from].push_back(to);
		graph[to].push_back(from);
	}
}

int bfs(int start) {
	queue<int> person;
	person.push(start);
	visited[start] = true;

	int cnt = 0;

	while (!person.empty()) {
		int personSize = person.size();
		cnt++;

		for (int i = 0; i < personSize; i++) {
			int curX = person.front();
			person.pop();

			for (int j = 0; j < graph[curX].size(); j++) {
				if (graph[curX][j] == secondPerson) return cnt;

				if (!visited[graph[curX][j]]) {
					person.push(graph[curX][j]);

					visited[graph[curX][j]] = true;
				}
			}
		}
	}

	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << bfs(firstPerson);

	return 0;
}
