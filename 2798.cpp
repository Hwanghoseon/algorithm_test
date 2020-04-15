#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 100;

int n, m;
int list[MAX];
int arr[3];
int result;

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> list[i];
}

void func(int cnt, int min) {
	if (cnt == 3) {
		int temp = 0;
		for (int i = 0; i < 3; i++)
			temp += arr[i];

		if (temp <= m)
			result = max(result, temp);

		return;
	}

	for (int i = min; i < n; i++) {
		arr[cnt] = list[i];
		func(cnt + 1, i + 1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func(0, 0);

	cout << result;

	return 0;
}
