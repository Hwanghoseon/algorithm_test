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

int list[10 + 1];
int N;
bool visited[10];
int len;
vector<int> arr;
bool isEnd = false;

void func() {
	list[1] = 10;

	for (int i = 2; i <= 10; i++) {
		list[i] = list[i - 1] * (10 + 1 - i);
		list[i] /= i;
	}

	list[1]--;

	for (int i = 1; i <= 10; i++)
		list[i] += list[i - 1];
}

void bt(int cnt, int idx) {
	if (isEnd) return;

	if (cnt == len) {
		N--;

		if (!N) {
			for (int i = 0; i < len; i++)
				cout << arr[i];

			isEnd = true;
		}

		return;
	}

	for (int i = 0; i < idx; i++) {
		if (!cnt && !i) continue;

		visited[i] = true;
		arr[cnt] = i;
		bt(cnt + 1, i);
		visited[i] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	func();

	cin >> N;

	if (!N) {
		cout << "0";
	}
	else if (N > list[10]) {
		cout << "-1";
	}
	else if (N == list[10]) {
		for (int i = 9; i >= 0; i--)
			cout << i;
	}
	else {
		for (int i = 1; i <= 10; i++) {
			if (N < list[i]) {
				len = i;

				break;
			}
		}
		N -= list[len - 1];

		if (!N) {
			len--;

			int cnt = 0;
			while (len--) {
				cout << 9 - cnt;

				cnt++;
			}
		}
		else {
			arr.resize(len);

			bt(0, 10);
		}
	}

	return 0;
}
