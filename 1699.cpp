#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX = 100000 + 1;

int cache[MAX];
int n;

void prefunc() {
	for (int i = 1; i * i <= n; i++)
		cache[i * i] = 1;
}

long long func() {
	for (int i = 2; i < MAX; i++) {
		if (cache[i] == 1) continue;

		cache[i] = MAX;
		for (int j = (int)sqrt(i); j >= 1; j--) {
			int cnt = 1 + cache[i - (j * j)];

			cache[i] = min(cnt, cache[i]);
		}
	}

	return cache[n];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	prefunc();

	cout << func();

	return 0;
}
