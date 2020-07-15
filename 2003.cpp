#include<iostream>

using namespace std;

const int MAX = 10000;

int n, m;
int arr[MAX];
int caseCnt = 0;	// 경우의 수
int startNum = 0;

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void func(int cnt, int sum) {
	if (sum == m) {
		caseCnt++;

		startNum++;
		return;
	}
	else if (sum > m) {
		startNum++;
		return;
	}

	if(cnt < n)
		func(cnt + 1, sum + arr[cnt]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	for (int i = 0; i < n; i++)
		func(0 + startNum, 0);

	//func(0, 0);

	cout << caseCnt;

	return 0;
}
