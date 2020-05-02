#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cstring>
#include<cmath>

using namespace std;

const int MAX = 1000000 + 1;

int list[MAX];

void input() {
	
}

void func() {
	int end = sqrt(MAX);

	for (int i = 2; i <= MAX; i++) {
		for (int j = i; j < MAX; j += i)
			list[j]++;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	func();

	while (true) {
		bool flag = false;
		int n;
		cin >> n;

		if (!n) break;

		for (int i = 2; i < n; i++) {
			if (list[i] == 1 && list[n - i] == 1) {
				cout << n << " = " << i << " + " << n - i << "\n";
				flag = true;
				break;
			}
		}

		if (!flag) cout << "Goldbach's conjecture is wrong.\n";
	}

	return 0;
}
