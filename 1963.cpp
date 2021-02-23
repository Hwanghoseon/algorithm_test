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

const int MAX = 1e5;

bool list[MAX];	// 소수 판별  소수 : false
bool visited[MAX];

void func() {
	list[0] = list[1] = true;

	for (int i = 2; i < MAX; i++) {
		if (i * i >= MAX) break;

		for (int j = i * i; j < MAX; j += i)
			list[j] = true;
	}
}

void bfs(int from, int to) {
	queue<pair<int, int>> q;	// 숫자, 횟수
	q.push(make_pair(from, 0));
	visited[from] = true;

	while (!q.empty()) {
		int curNum = q.front().first;
		int curCnt = q.front().second;
		q.pop();

		if (curNum == to) {
			cout << curCnt << "\n";
			return;
		}

		int fourthNum = curNum % 10;
		curNum /= 10;
		int thirdNum = curNum % 10;
		curNum /= 10;
		int secondNum = curNum % 10;
		curNum /= 10;
		int firstNum = curNum;

		for (int i = 0; i < 10; i++) {
			int temp;

			// 첫번째 숫자
			if (i != 0) {
				temp = 0;

				temp += i * 1000;
				temp += secondNum * 100;
				temp += thirdNum * 10;
				temp += fourthNum;

				if (!visited[temp] && !list[temp]) {
					visited[temp] = true;

					q.push(make_pair(temp, curCnt + 1));
				}
			}

			// 두번째 숫자
			temp = 0;

			temp += firstNum * 1000;
			temp += i * 100;
			temp += thirdNum * 10;
			temp += fourthNum;

			if (!visited[temp] && !list[temp]) {
				visited[temp] = true;

				q.push(make_pair(temp, curCnt + 1));
			}

			// 세번째 숫자
			temp = 0;

			temp += firstNum * 1000;
			temp += secondNum * 100;
			temp += i * 10;
			temp += fourthNum;

			if (!visited[temp] && !list[temp]) {
				visited[temp] = true;

				q.push(make_pair(temp, curCnt + 1));
			}

			// 넷번째 숫자
			temp = 0;

			temp += firstNum * 1000;
			temp += secondNum * 100;
			temp += thirdNum * 10;
			temp += i;

			if (!visited[temp] && !list[temp]) {
				visited[temp] = true;

				q.push(make_pair(temp, curCnt + 1));
			}
		}
	}

	cout << "Impossible\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	func();

	int T;
	cin >> T;

	while (T--) {
		int from, to;
		cin >> from >> to;

		memset(visited, false, sizeof(visited));

		bfs(from, to);
	}

	return 0;
}
