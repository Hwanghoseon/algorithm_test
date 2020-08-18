#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 1100000;

vector<int> list(MAX);
int n;

void func() {
	for (int i = 1; i <= n; i++) {
		int temp = i;
		int sum = i;

		while (temp) {
			sum += (temp % 10);

			temp /= 10;
		}

		if (list[sum])
			list[sum] = min(list[sum], i);
		else list[sum] = i;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	func();

	cout << list[n];

	return 0;
}
