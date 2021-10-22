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

const int MAX = 30;

int N;
int list[MAX];
int cache[MAX + 1][MAX * 500 + 1];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> list[i];
}

void bt(int idx, int sum) {
	if (idx > N) return;

	int &result = cache[idx][sum];
	if (result != -1) return;

	result = 1;

	bt(idx + 1, sum + list[idx]);
	bt(idx + 1, sum);
	bt(idx + 1, abs(sum - list[idx]));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	memset(cache, -1, sizeof(cache));

	bt(0, 0);

	int T;
	cin >> T;

	while (T--) {
		int weight;
		cin >> weight;

		if (weight > MAX * 500)
			cout << "N ";
		else if (cache[N][weight] == 1)
			cout << "Y ";
		else cout << "N ";
	}

	return 0;
}
