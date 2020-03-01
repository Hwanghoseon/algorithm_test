#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

const int MAX = 1000;

char map[MAX][MAX];
bool visit[MAX][MAX];
queue<pair<int, int>> fire;
queue<pair<int, int>> person;
int w, h;
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };
bool flag = false;
int cnt;

void input() {
	memset(map, false, sizeof(map));
	memset(visit, false, sizeof(visit));
	
	while (!fire.empty()) fire.pop();
	while (!person.empty()) person.pop();

	cin >> h >> w;	// x는 w y는 h

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			cin >> map[i][j];

			if (map[i][j] == '*')
				fire.push(make_pair(i, j));
			else if (map[i][j] == '@') {
				person.push(make_pair(i, j));
				visit[i][j] = true;
			}
		}
	}
}

void bfsPerson() { // 상근 이동 경로
	int personNum = person.size();

	for(int k = 0; k < personNum; k++) {
		int x = person.front().first;
		int y = person.front().second;
		
		if (map[x][y] != '@') {
			person.pop();
			continue;
		}

		person.pop();
		map[x][y] = '.';	// 이동한 자리는 '.'로 바꿔준다.

		for (int i = 0; i < 4; i++) {
			int nextX = x + dirX[i];
			int nextY = y + dirY[i];

			if (nextX >= 0 && nextX < w && nextY >= 0 && nextY < h) {
				if (map[nextX][nextY] == '.' && !visit[nextX][nextY]) {
					person.push(make_pair(nextX, nextY));
					map[nextX][nextY] = '@';
					visit[nextX][nextY] = true;
				}
			}
			else {
				flag = true;
				cnt++;
				return;
			}
		}
	}
}

void bfsFire() {
	int fireSize = fire.size();

	for (int i = 0; i < fireSize; i++) {
		int curX = fire.front().first;
		int curY = fire.front().second;
		fire.pop();
		 
		for (int j = 0; j < 4; j++) {
			int nextX = curX + dirX[j];
			int nextY = curY + dirY[j];

			if (nextX >= 0 && nextX < w && nextY >= 0 && nextY < h) {
				if (map[nextX][nextY] == '.') {
					fire.push(make_pair(nextX, nextY));
					map[nextX][nextY] = '*';
				}
				else if (map[nextX][nextY] == '@') {
					fire.push(make_pair(nextX, nextY));
					map[nextX][nextY] = '*';
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		input();
		flag = false;
		cnt = 0;

		while (!person.empty()) {
			bfsPerson();
			
			if (flag) break;

			bfsFire();

			cnt++;
		}

		if(flag)
			cout << cnt << "\n";
		else cout << "IMPOSSIBLE" << "\n";
	}

	return 0;
}
