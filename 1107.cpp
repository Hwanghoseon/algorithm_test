#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

const int MAX = 500000;

int n, m;
int len = 0;	// 이동하려는 채널의 자릿수
int checkSize = 0;
int list[10];
int buttonCnt = 0;	// 버튼을 누른 횟수
vector<int> arr;

void input() {
	cin >> n >> m;

	int temp = n;
	// 이동할 버튼의 자릿수
	while (temp) {
		len++;
		temp /= 10;
	}
	if (n == 0) len = 1;

	// 고장난 버튼 1
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;

		list[temp] = 1;
	}
}

void func(int cnt) {
	if (cnt == checkSize) {
		int sum = 0;
		for (int i = 0; i < arr.size(); i++)
			sum += (arr[i] * pow(10, checkSize - i - 1));

		int gap = abs(n - sum);

		buttonCnt = min(buttonCnt, gap + checkSize);

		return;
	}
	
	for (int i = 0; i < 10; i++) {

		if (!list[i]) {
			arr.push_back(i);
			func(cnt + 1);
			arr.pop_back();
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	buttonCnt = abs(n - 100);
	
	int sz[3] = { -1, 0, 1 };
	for (int i = 0; i < 3; i++) {
		checkSize = len + sz[i];

		if (checkSize <= 0 || checkSize > 6) continue;
		func(0);
	}

	cout << buttonCnt;

	return 0;
}
