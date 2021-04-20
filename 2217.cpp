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

const int MAX = 1e5;

int N;
vector<int> list;

void input() {
	cin >> N;

	list.resize(N);

	for (int i = 0; i < N; i++)
		cin >> list[i];

	sort(list.begin(), list.end());
}

int solution() {
	int weight = 0;

	for (int i = 0; i < N; i++) {
		int temp = list[i] * (N - i);

		weight = max(weight, temp);
	}

	return weight;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
