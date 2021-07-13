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

const int MAX = 1000 + 1;

long long list[MAX][10 + 1];

void func() {
	for (int i = 1; i <= 10; i++)
		list[0][i] = 1;

	for (int i = 1; i < MAX; i++)
		for (int j = 1; j <= 10; j++)
			list[i][j] = list[i - 1][j] + list[i][j - 1];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	func();

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		cout << list[N][10] << "\n";
	}

	return 0;
}
