#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 15;

vector<char> list;
char arr[MAX];	// 가능한 암호를 저장하기 위한 배열
bool visit[MAX];
int n, m;

void input() {
	cin >> m >> n;

	list.resize(n);

	for (int i = 0; i < n; i++)
		cin >> list[i];

	sort(list.begin(), list.end());
}

bool check() {
	bool flag = false;;

	int conCnt = 0;
	int vowCnt = 0;

	for (int i = 0; i < m; i++) {
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			vowCnt++;
		else conCnt++;
	}

	if (vowCnt >= 1 && conCnt >= 2) flag = true;
	else false;

	return flag;
}

void func(int cnt, int min) {
	if (cnt == m) {
		if (check()) {
			for (int i = 0; i < m; i++)
				cout << arr[i];
			cout << "\n";

			return;
		}
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

	return 0;
}
