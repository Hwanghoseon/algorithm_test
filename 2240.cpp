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

using namespace std;

const int MAX = 1000;
const int MOVE = 30 + 1;

int T, W;
int list[MAX];
int cache[3][MAX][MOVE];

void input() {
	cin >> T >> W;

	for (int i = 0; i < T; i++)
		cin >> list[i];
}

int maxCnt(int tree, int second, int move) {
	// 기저 사례
	if (second == T) return 0;

	int &result = cache[tree][second][move];

	if (result != -1) return result;

	// 자두가 현재의 나무에서 떨어질 경우
	if (list[second] == tree) {
		// 움직일 수 있는 경우
		if(move < W)
			return result = max(1 + maxCnt(tree, second + 1, move), maxCnt(3 - tree, second + 1, move + 1));
		// 움직일 수 없는 경우
		else return result = 1 + maxCnt(tree, second + 1, move);
	}
	// 자두가 다른 나무에서 떨어질 경우
	else {
		// 움직일 수 있는 경우
		if (move < W)
			return result = max(maxCnt(tree, second + 1, move), 1 + maxCnt(3 - tree, second + 1, move + 1));
		// 움직일 수 없는 경우
		else return result = maxCnt(tree, second + 1, move);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	memset(cache, -1, sizeof(cache));

	cout << maxCnt(1, 0, 0);

	return 0;
}
