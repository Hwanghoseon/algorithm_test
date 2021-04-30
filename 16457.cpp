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

const int MAX = 100 + 1;

int N, M, K;
vector<int> list[MAX];
int temp = 0;
bool visited[10 * 2 + 1];

void input() {
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			int key;
			cin >> key;

			list[i].push_back(key);
		}
	}
}

int checkSum() {
	int cnt = 0;

	for (int i = 0; i < M; i++) {
		bool isFalse = false;
		for (int j = 0; j < list[i].size(); j++) {
			if (!visited[list[i][j]]) {
				isFalse = true;

				break;
			}
		}
		if (isFalse) continue;

		cnt++;
	}

	return cnt;
}

void func(int cnt, int idx) {
	if (cnt == N) {
		temp = max(temp, checkSum());

		return;
	}

	/*for (int i = idx; i <= N * 2; i++) {
		visited[idx] = true;
		func(cnt + 1, idx + 1);
		visited[idx] = false;
	}*/

	if (idx > 2 * N) return;

	visited[idx] = true;
	func(cnt + 1, idx + 1);
	visited[idx] = false;
	func(cnt, idx + 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func(0, 1);

	cout << temp;

	return 0;
}
