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
deque<pair<int, int>> list;	//	value, idx

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;

		list.push_back({ temp, i });
	}
}

void func() {
	while (true) {
		int curValue = list.front().first;
		int curIdx = list.front().second;
		list.pop_front();

		cout << curIdx << " ";

		if (list.empty()) break;

		if (curValue > 0) {
			curValue--;

			while (curValue--) {
				int tempValue = list.front().first;
				int tempIdx = list.front().second;
				list.pop_front();

				list.push_back({ tempValue, tempIdx });
			}
		}
		else {
			curValue = abs(curValue);

			while (curValue--) {
				int tempValue = list.back().first;
				int tempIdx = list.back().second;
				list.pop_back();

				list.push_front({ tempValue, tempIdx });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func();

	return 0;
}
