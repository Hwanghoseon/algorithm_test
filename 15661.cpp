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

const int MAX = 20 + 1;

int N, result = INT_MAX;
int board[MAX][MAX];
bool visited[MAX];

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];
}

int checkSum() {
	int sumLink, sumStart;
	sumLink = sumStart = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i] && visited[j]) sumLink += board[i][j];

			if (!visited[i] && !visited[j]) sumStart += board[i][j];
		}
	}

	return abs(sumLink - sumStart);
}

void func(int idx, int cnt, int num) {
	if (cnt == num) {
		result = min(result, checkSum());

		return;
	}

	if (idx == N) return;

	visited[idx] = true;
	func(idx + 1, cnt + 1, num);
	
	visited[idx] = false;
	func(idx + 1, cnt, num);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	for (int i = 1; i <= N; i++) 
		func(1, 0, i);

	cout << result;

	return 0;
}
