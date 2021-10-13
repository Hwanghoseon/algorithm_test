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

const int MAX = 500 + 1;

int N;
int arr[MAX][2];
int cache[MAX][MAX];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i][0] >> arr[i][1];
}

int minCalc(int left, int right) {
	if (left == right) return 0;

	int &result = cache[left][right];
	if (result != -1) return result;

	result = INT_MAX;

	for (int i = left; i < right; i++)
		result = min(result, minCalc(left, i) + minCalc(i + 1, right) + (arr[left][0] * arr[i][1] * arr[right][1]));

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	
	memset(cache, -1, sizeof(cache));

	cout << minCalc(0, N - 1);

	return 0;
}
