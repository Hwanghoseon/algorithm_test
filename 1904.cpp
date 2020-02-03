#include<iostream>

using namespace std;

int const MAX = 1000000;
int const MOD = 15746;

int n;
int cache[MAX + 1];

void kindsofBinary() {
	cache[1] = 1;	// 1
	cache[2] = 2;	// 00, 11

	// 100, 001, 111     cache[3] = 3
	// 0000 0011 1001 0011 1111     cache = 5
	// 11111 10000 00100 00001 11100 11001 10011 00011     cache = 8

	for (int i = 3; i <= MAX; i++)
		cache[i] = (cache[i - 2] + cache[i - 1]) % MOD;

	cout << cache[n];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	kindsofBinary();

	return 0;
}
