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

const int MAX = 50;
const int INF = 987654321;

int N;
int list[MAX][MAX];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string st;
		cin >> st;

		fill(list[i], list[i] + N, INF);

		for (int j = 0; j < st.length(); j++) {
			if (i == j) list[i][j] = 0;
			else if (st[j] == 'Y') list[i][j] = 1;
		}
	}
}

int func() {
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (i == j || j == k || i == k) continue;

				if (list[i][j] > list[i][k] + list[k][j]) {
					list[i][j] = list[i][k] + list[k][j];
				}
			}

	for (int i = 0; i < N; i++)
		list[i][i] = 0;

	int result = 0;

	for (int i = 0; i < N; i++) {
		int cnt = 0;

		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			if (list[i][j] <= 2)
				cnt++;
		}

		result = max(result, cnt);
	}

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << func();

	return 0;
}
