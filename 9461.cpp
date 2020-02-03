#include<iostream>

using namespace std;

const int MAX = 100 + 1;

int n;
long long cache[MAX];

void sqCount() {
	cache[1] = 1;
	cache[2] = 1;
	cache[3] = 1;
	cache[4] = 2;
	cache[5] = 2;

	// cache[6] = 3  5 + 1
	// cache[7] = 4  6 + 2
	// caceh[8] = 5  7 + 3
	// cache[9] = 7  8 + 4
	// cache[10] = 9 9 + 5

	for (int i = 6; i < MAX; i++)
		cache[i] = cache[i - 1] + cache[i - 5];

	cout << cache[n] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		cin >> n;

		sqCount();
	}

	return 0;
}
