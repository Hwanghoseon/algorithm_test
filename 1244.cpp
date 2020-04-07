#include<iostream>

using namespace std;

const int MAX = 100 + 1;

int list[MAX];
int n, m;

void input() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> list[i];
}

void func(int gender, int cur) {
	if (gender == 1) {
		for (int i = cur; i <= n; i += cur) {
			if (list[i] == 1) list[i] = 0;
			else list[i] = 1;
		}
	}
	else if (gender == 2) {
		for (int i = 0; ; i++) {
			if (cur - i >= 1 && cur + i <= n) {
				if (list[cur - i] == list[cur + i]) {
					if (list[cur + i] == 1) {
						list[cur + i] = 0;
						list[cur - i] = 0;
					}
					else {
						list[cur + i] = 1;
						list[cur - i] = 1;
					}
				}
				else return;
			}
			else return;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	input();

	cin >> m;

	while (m--) {
		int gender, cur;
		cin >> gender >> cur;

		func(gender, cur);
	}

	for (int i = 1; i <= n; i++) {
		cout << list[i] << " ";

		if (i % 20 == 0) cout << "\n";
	}

	

	return 0;
}
