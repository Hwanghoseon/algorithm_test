#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 13;

vector<int> list;
vector<int> arr;	// 입력값 저장
bool visit[MAX];
int n;

void input() {
	arr.resize(n);
	list.resize(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
}

void func(int cnt, int min) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++)
			cout << list[i] << " ";
		cout << "\n";

		return;
	}

	for (int i = min; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			list[cnt] = arr[i];
			func(cnt + 1, i + 1);
			visit[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> n;

		if (n == 0)
			break;

		input();

		func(0, 0);
		cout << "\n";
	}

	return 0;
}
