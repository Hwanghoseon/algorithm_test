#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cstring>
#include<cmath>

using namespace std;

const int MAX = 1000 + 1;

int list[MAX];

void input() {
	
}

void func(int y, int x) {
	int end = sqrt(MAX);
	int cnt = 0;

	for (int i = 2; i <= y; i++) {
		for (int j = i; j <= y; j += i) {
			if (!list[j]) {
				list[j]++;
				cnt++;

				if (cnt == x) {
					cout << j;
					return;
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	func(n, k);

	return 0;
}
