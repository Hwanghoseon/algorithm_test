#include<iostream>
#include<cstring>

using namespace std;

const int MAX = 100;

int n;
int list[MAX];
long long cache[20 + 1][MAX];	// sum, idx

void input() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> list[i];
}

long long func(int sum, int idx) {
	// 범위를 벗어날 경우
	if (sum < 0 || sum > 20)
		return 0;
	// 조건을 만족시킬 경우
	if (idx == n - 2)
		return (sum == list[idx + 1]);

	long long &result = cache[sum][idx];

	if (result != -1) return result;

	result = 0;

	return result += (func(sum - list[idx + 1], idx + 1) + func(sum + list[idx + 1], idx + 1));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	memset(cache, -1, sizeof(cache));

	cout << func(list[0], 0);

	return 0;
}
