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

const int MAX = 1e6;

int N, target;
vector<int> list;

void input() {
	cin >> N;

	list.resize(N);

	for (int i = 0; i < N; i++)
		cin >> list[i];

	cin >> target;

	sort(list.begin(), list.end());
}

int solution() {
	int ans = 0;
	int low = 0;
	int high = N - 1;

	while (low < high) {
		int sum = list[low] + list[high];

		if (sum == target) {
			ans++;

			low++;
			high--;
		}
		else if (sum < target)
			low++;
		else high--;
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
