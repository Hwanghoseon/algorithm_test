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

const int MAX = 1e6;

int N, M;
vector<int> list;

void input() {
	cin >> N >> M;

	list.resize(N + M);

	for (int i = 0; i < N + M; i++)
		cin >> list[i];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	sort(list.begin(), list.end());

	for (int i = 0; i < list.size(); i++)
		cout << list[i] << " ";

	return 0;
}
