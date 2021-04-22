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

int N, H;
vector<int> top;
vector<int> bottom;
int cnt = 0;
int result = INT_MAX;

void input() {
	cin >> N >> H;

	top.resize(N / 2);
	bottom.resize(N / 2);

	for (int i = 0; i < N / 2; i++)
		cin >> bottom[i] >> top[i];

	sort(top.begin(), top.end());
	sort(bottom.begin(), bottom.end());
}

void binarySearch() {
	for (int i = 1; i <= H; i++) {
		int temp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());

		temp += top.size() - (upper_bound(top.begin(), top.end(), H - i) - top.begin());

		if (temp == result) cnt++;
		else if (temp < result) {
			result = temp;

			cnt = 1;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	binarySearch();

	cout << result << " " << cnt;

	return 0;
}
