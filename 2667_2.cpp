#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 25;

bool visit[MAX][MAX] = { false };
vector<int> v;	// 단지 내의 아파트 단지 수
string graph[MAX];

int N, cnt;
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };

void dfs(int x, int y) {
	cnt++;
	visit[x][y] = true;

	for (int i = 0; i < N; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N)
			if(graph[nextX][nextY] == '1' && !visit[nextX][nextY])
				dfs(nextX, nextY);
	}
}

bool desc(int a, int b) {
	return a > b;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> graph[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == '1' && !visit[i][j]) {
				cnt = 0;
				dfs(i, j);
				v.push_back(cnt);
			}
		}
	}

	sort(v.begin(), v.end(), desc);

	int size = v.size();

	cout << size << endl;

	for (int i = 0; i < size; i++) {
		cout << v.back() << endl;
		v.pop_back();
	}

	return 0;
}
