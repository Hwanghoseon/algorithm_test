#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 25;

int map[MAX][MAX];
bool visit[MAX][MAX] = { false };
string s[MAX];	// 지도 한줄씩 체크
vector<int> v;	// 단지 내 단지의 수 체크 벡터
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };

int N, cnt;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visit[x][y] = true;

	int first, second;
	
	while (!q.empty()) {
		first = q.front().first;	// y  0
		second = q.front().second;	// x  1
		
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++) {
			int nextX = first + dirX[i];
			int nextY = second + dirY[i];
			
			if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < N){
				if (map[nextX][nextY] && !visit[nextX][nextY]) {
					q.push({ nextX, nextY });
					visit[nextX][nextY] = true;
				}
			}
		}
	}

	v.push_back(cnt);
}

bool desc(int a, int b) {
	return a > b;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> s[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = s[i][j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] && !visit[i][j]) {
				cnt = 0;
				bfs(i, j);
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
