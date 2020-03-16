#include<iostream>
#include<vector>

using namespace std;

const int MAX = 20;

int n;
int result;
int list[MAX];
int arr[MAX];
bool visit[MAX];
int sumCnt = 0;

void input() {
	cin >> n >> result;
	
	for (int i = 0; i < n; i++)
		cin >> list[i];
}

bool check(int num) {
	if (num == 0) return false;

	int sum = 0;
	for (int i = 0; i < num; i++)
		sum += arr[i];

	if (sum == result) return true;
	else return false;
}

void func(int cnt, int min) {
	if (check(cnt)) {
		sumCnt++;

		//return;
	}

	for (int i = min; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[cnt] = list[i];
			func(cnt + 1, i + 1);
			visit[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func(0, 0);

	cout << sumCnt;

	return 0;
}
