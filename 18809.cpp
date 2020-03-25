#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX = 50;
int flower = 0;
int N, M, R, G;
int town[MAX][MAX];
int Town[MAX][MAX];
bool check[MAX][MAX];
queue<pair<int, int>> red;
queue<pair<int, int>> green;
vector<pair<int, int>> redPossible;
vector<pair<int, int>> greenPossible;
vector<pair<int, int>> possibleLand;   //배양액을 뿌릴 수 있는 땅
bool visit[10];
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0 ,0, 1, -1 };
vector<int> flowerMax;

void input() {
	cin >> N >> M >> R >> G;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Town[i][j];

			if (Town[i][j] == 2)
				possibleLand.push_back(make_pair(i, j));
		}
	}
}

bool desc(int a, int b) {
	return a > b;
}

void bfs() {
	flower = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			town[i][j] = Town[i][j];

	for (int i = 0; i < redPossible.size(); i++) {
		int redX = redPossible[i].first;
		int redY = redPossible[i].second;
		red.push(make_pair(redX, redY));
		town[redX][redY] = 3;
		check[redX][redY] = true;
	}

	for (int i = 0; i < greenPossible.size(); i++) {
		int greenX = greenPossible[i].first;
		int greenY = greenPossible[i].second;
		green.push(make_pair(greenX, greenY));
		town[greenX][greenY] = 4;
		check[greenX][greenY] = true;
	}

	while (!red.empty() || !green.empty()) {
		int redSize = red.size();

		for (int j = 0; j < redSize; j++) {
			int redCurX = red.front().first;
			int redCurY = red.front().second;

			town[redCurX][redCurY] = 0;
			red.pop();

			for (int i = 0; i < 4; i++) {
				int redNextX = redCurX + dirX[i];
				int redNextY = redCurY + dirY[i];

				if (redNextX >= 0 && redNextX < N && redNextY >= 0 && redNextY < M) {
					if (town[redNextX][redNextY] == 1 || town[redNextX][redNextY] == 2) {
						if (!check[redNextX][redNextY]) {
							check[redNextX][redNextY] = true;
							red.push(make_pair(redNextX, redNextY));
							town[redNextX][redNextY] = 3;
						}
					}
				}
			}
		}

		int greenSize = green.size();

		for (int j = 0; j < greenSize; j++) {
			int greenCurX = green.front().first;
			int greenCurY = green.front().second;
			town[greenCurX][greenCurY] = 0;
			green.pop();

			for (int i = 0; i < 4; i++) {
				int greenNextX = greenCurX + dirX[i];
				int greenNextY = greenCurY + dirY[i];

				if (greenNextX >= 0 && greenNextX < N && greenNextY >= 0 && greenNextY < M) {
					if (town[greenNextX][greenNextY] == 1 || town[greenNextX][greenNextY] == 2) {
						if (!check[greenNextX][greenNextY]) {
							check[greenNextX][greenNextY] = true;
							green.push(make_pair(greenNextX, greenNextY));
							town[greenNextX][greenNextY] = 4;
						}
					}
					else if (town[greenNextX][greenNextY] == 3) {
						town[greenNextX][greenNextY] = 5;
						check[greenNextX][greenNextY] = true;
						flower++;
					}
				}
			}
		}

		int redCheck = red.size();

		for (int i = 0; i < redCheck; i++) {
			int redCurX = red.front().first;
			int redCurY = red.front().second;

			if (town[redCurX][redCurY] == 5)
				red.pop();
			else {
				red.pop();
				red.push(make_pair(redCurX, redCurY));
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			check[i][j] = false;

	flowerMax.push_back(flower);
}

void Gfunc(int cnt, int min) {
	if (cnt == G) {
		bfs();

		return;
	}

	for (int i = min; i < possibleLand.size(); i++) {
		if (!visit[i]) {
			visit[i] = true;
			greenPossible.push_back(make_pair(possibleLand[i].first, possibleLand[i].second));
			Gfunc(cnt + 1, i + 1);
			visit[i] = false;
			greenPossible.pop_back();
		}
	}
}

void Rfunc(int cnt, int min) {
	if (cnt == R) {
		Gfunc(0, 0);

		return;
	}

	for (int i = min; i < possibleLand.size(); i++) {
		if (!visit[i]) {
			visit[i] = true;
			redPossible.push_back(make_pair(possibleLand[i].first, possibleLand[i].second));
			Rfunc(cnt + 1, i + 1);
			redPossible.pop_back();
			visit[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	Rfunc(0, 0);

	sort(flowerMax.begin(), flowerMax.end(), desc);

	cout << flowerMax[0];

	return 0;
}
