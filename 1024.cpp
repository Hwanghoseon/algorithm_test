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

int N, L;

void func() {
	for (int i = L; i <= 100; i++) {
		int temp = N - (i * (i + 1)) / 2;

		if (temp % i == 0) {
			int j = temp / i + 1;

			if (j >= 0) {
				for (int k = 0; k < i; k++)
					cout << j + k << " ";

				return;
			}
		}
	}

	cout << -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;

	func();

	return 0;
}
