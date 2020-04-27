#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 8;
int n;
int arr[MAX];
int list[MAX];
bool visit[MAX];
int result = 0;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> list[i];
}

int calculation() {
	int sum = 0;
	for (int i = 0; i < n - 1; i++)
		sum += abs(arr[i] - arr[i + 1]);

	return sum;
}

void func(int cnt) {
	if (cnt == n) {
		result = max(result, calculation());

		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[cnt] = list[i];
			func(cnt + 1);
			visit[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func(0);

	cout << result;

	return 0;
}
