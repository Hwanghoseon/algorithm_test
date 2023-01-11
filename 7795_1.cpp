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

int N, M;
vector<int> list, arr;

void input() {
	cin >> N >> M;

	list.resize(N);
	arr.resize(M);

	for (int i = 0; i < N; i++)
		cin >> list[i];

	for (int i = 0; i < M; i++)
		cin >> arr[i];

	sort(list.begin(), list.end());
	sort(arr.begin(), arr.end());
}

int solution() {
	int listPoint = 0;
	int arrPoint = 0;
	int cnt = 0;

	while (listPoint != N) {
		if (arrPoint == M) {
			listPoint++;
			cnt += arrPoint;

			continue;
		}

		if (list[listPoint] > arr[arrPoint])
			arrPoint++;
		else {
			cnt += arrPoint;

			listPoint++;
		}
	}

	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		input();

		cout << solution() << "\n";
	}

	return 0;
}
