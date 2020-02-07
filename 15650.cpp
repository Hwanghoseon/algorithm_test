#include<iostream>
#include<vector>

using namespace std;

const int MAX = 8 + 1;
vector<int> arr;
bool visit[MAX];
int n, m;

void func(int cnt, int min) {
	// 수열의 수가 다 찼을 때
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}

	for (int i = min; i <= n; i++) {	// min으로 중복 제거
		if (!visit[i]) {
			visit[i] = true;
			arr[cnt] = i;
			func(cnt + 1, i + 1);
			visit[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	arr.resize(n);

	func(0, 1);

	return 0;
}
