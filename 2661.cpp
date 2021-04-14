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

int N;
bool isEnd = false;

bool isValid(string input) {
	int len = input.length();
	int endPoint = len - 1;

	for (int i = 1; i <= len / 2; i++) {
		string first = input.substr(endPoint - i, i);
		string second = input.substr(endPoint, i);

		if (first == second) return false;

		endPoint--;
	}

	return true;
}

void func(int cnt, string s) {
	if (isEnd) return;

	if(!isValid(s)) return;

	if (cnt == N) {
		cout << s;

		isEnd = true;
	}

	func(cnt + 1, s + '1');

	func(cnt + 1, s + '2');

	func(cnt + 1, s + '3');
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	func(0, "");

	return 0;
}
