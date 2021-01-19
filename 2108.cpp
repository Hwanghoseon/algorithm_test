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

const int MAX = 4000 * 2 + 1;

int N;
double sum = 0;
vector<int> list;
int visited[MAX];

void input() {
	cin >> N;

	list.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> list[i];
		sum += list[i];

		visited[list[i] + 4000]++;
	}

	sort(list.begin(), list.end());
}

int addList() {
	double result = sum;

	result /= N;

	return round(result);
}

int cntNum() {
	vector<pair<int, int>> arr;

	for (int i = 0; i < MAX; i++) {
		if (visited[i])
			arr.push_back(make_pair(visited[i], i - 4000));
	}

	sort(arr.begin(), arr.end());

	int len = arr.size();

	// 값이 하나만 있을 경우
	if (len == 1)
		return arr[0].second;

	// 최빈값이 한 개 있을 경우
	if (arr[len - 1].first != arr[len - 2].first)
		return arr[len - 1].second;

	// 최빈값이 두 개 이상인 경우
	for (int i = len - 1; i >= 0; i--) {
		if (arr[i].first == arr[len - 1].first)
			continue;
		else return arr[i + 2].second;
	}

	return arr[1].second;
}

void solution() {
	// 산술평균 값
	cout << addList() << "\n";

	// 중앙값
	cout << list[N / 2] << "\n";

	// 최빈값
	cout << cntNum() << "\n";

	// 범위
	if (list.size() == 1)
		cout << 0 << "\n";
	else cout << list[N - 1] - list[0] << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();

	return 0;
}
