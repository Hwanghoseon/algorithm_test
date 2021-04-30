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

const int MAX = 10;

int N;
int list[MAX];
int sumList[MAX];
int arr[MAX];
bool visited[MAX];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> list[i];
}

bool checkList() {
	for (int i = 0; i < N; i++) {
		int cnt = 0;

		for (int j = 0; j <= i - 1; j++)
			if (arr[i] < arr[j]) cnt++;

		sumList[arr[i]] = cnt;
	}

	for (int i = 0; i < N; i++)
		if (list[i] != sumList[i + 1]) return false;

	return true;
}

void func(int cnt) {
	if (cnt == N) {
		if (checkList()) {
			for (int i = 0; i < N; i++)
				cout << arr[i] << " ";
		}

		/*for (int i = 0; i < N; i++)
			cout << arr[i] << " ";

		cout << "\n";*/

		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt] = i;
			func(cnt + 1);
			visited[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func(0);

	return 0;
}
