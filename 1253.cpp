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

const int MAX = 2000 + 1;

int N;
vector<int> list;
int num[MAX];

void input() {
	cin >> N;
	
	list.resize(N);

	for (int i = 0; i < N; i++)
		cin >> list[i];

	sort(list.begin(), list.end());
}

int solution() {
	int ans = 0;

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			int target = i - j;

			int low = 0;
			int high = N - 1;

			if (target < list[low] || target > list[high]) continue;

			while (low <= high) {
				int mid = (low + high) / 2;

				
			}
		}
	}*/

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			int target = list[i] - list[j];

			int low = lower_bound(list.begin(), list.end(), target) - list.begin();
			int high = upper_bound(list.begin(), list.end(), target) - list.begin();

			if (list[low] != target) continue;

			int temp = high - low;

			if (i >= low && i < high) temp--;
			if (j >= low && j < high) temp--;

			if (temp) num[i] = 1;
		}
	}

	for (int i = 0; i < N; i++)
		ans += num[i];

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
