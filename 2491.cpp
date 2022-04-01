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

const int MAX = 1e5 + 1;

int N;
int list[MAX];

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> list[i];
}

int solution() {
	vector<int> arr;
	arr.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		if (list[i] >= list[i - 1])
			arr[i] += arr[i - 1] + 1;
		else arr[i] = 1;
	}

	vector<int> reverseArr;
	reverseArr.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		if (list[i] <= list[i - 1])
			reverseArr[i] = reverseArr[i - 1] + 1;
		else reverseArr[i] = 1;
	}

	sort(arr.begin(), arr.end());
	sort(reverseArr.begin(), reverseArr.end());

	int ans = max(arr[N], reverseArr[N]);

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
