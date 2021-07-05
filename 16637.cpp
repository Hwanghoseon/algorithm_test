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
string input;
int result = INT_MIN;

int calculation(int x, int y, char op) {
	if (op == '+')
		return x + y;
	else if (op == '-')
		return x - y;
	else
		return x * y;
}

void bt(int idx, int value) {
	if (idx >= N) {
		result = max(result, value);

		return;
	}

	char op = idx > 0 ? input[idx - 1] : '+';
	int temp = calculation(value, input[idx] - '0', op);

	bt(idx + 2, temp);

	if (idx + 2 < N) {
		temp = calculation(input[idx] - '0', input[idx + 2] - '0', input[idx + 1]);
		temp = calculation(value, temp, op);

		bt(idx + 4, temp);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> input;

	bt(0, 0);

	cout << result;

	return 0;
}
