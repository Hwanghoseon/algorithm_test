#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 1000 + 1;

int N, M, L;
vector<int> list;
vector<int> gap;

void input() {
	cin >> N >> M >> L;

	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;

		list.push_back(temp);
	}
	list.push_back(0);	// 고속도로 처음
	list.push_back(L);	// 고속도로 끝
	
	sort(list.begin(), list.end());

	for (int i = 0; i < list.size() - 1; i++) {
		int temp = list[i + 1] - list[i];

		gap.push_back(temp);
	}

	sort(gap.begin(), gap.end());
}

int check(int x) {
	int cnt = 0;

	for (int i = 0; i < gap.size(); i++) {
		if (gap[i] % x == 0)
			cnt += (gap[i] / x - 1);
		else cnt += (gap[i] / x);
	}

	if (cnt <= M)
		return true;
	return false;
}

int binarySearch(int start, int end) {
	int result;

	while (start <= end) {
		int mid = (start + end) / 2;

		if (check(mid)) {
			result = mid;
			end = mid - 1;
		}
		else start = mid + 1;
	}

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << binarySearch(0, L);

	return 0;
}
