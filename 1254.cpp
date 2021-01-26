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

using namespace std;

string input;

bool isPossible(int cnt, int mid, int len) {
	for (int i = cnt; i <= mid; i++)
		if (input[i] != input[len + cnt - i - 1])
			return false;

	return true;
}

int solution() {
	int len = input.length();

	int cnt = 0;

	while (cnt < len) {
		int mid = (len + cnt) / 2;

		if ((len + cnt) % 2 == 0) mid--;

		if (isPossible(cnt, mid, len))
			return cnt + len;

		cnt++;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> input;

	cout << solution();

	return 0;
}
