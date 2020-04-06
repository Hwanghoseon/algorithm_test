#include<iostream>

using namespace std;

const int MAX = 10000000;

void func(int x) {
	for (int i = 2; i < MAX; i++) {
		while (x % i == 0) {
			x /= i;
			cout << i << "\n";
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	func(n);

	return 0;
}
