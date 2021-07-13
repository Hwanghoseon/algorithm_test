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

int H, W;
int height[MAX];

void input() {
	cin >> H >> W;

	for (int i = 1; i <= W; i++)
		cin >> height[i];
}

int solution() {
	int result = 0;

	for (int i = 2; i < W; i++) {
		int left, right;
		left = right = 0;

		for (int j = 1; j < i; j++)
			left = max(left, height[j]);

		for (int j = i + 1; j <= W; j++)
			right = max(right, height[j]);

		int temp = min(left, right) - height[i];

		if (temp >= 0)
			result += temp;
	}

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
