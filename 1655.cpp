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

using namespace std;

const int MAX = 10000 + 1;

priority_queue<int> minPQ;
priority_queue<int, vector<int>, greater<int>> maxPQ;
int N;
int mid = MAX;
int cnt = 0;

void balance() {
	// maxPQ와 minPQ의 size 크기가 1개 이하가 되도록 조정한다.
	int left = minPQ.size();
	int right = maxPQ.size();

	if (left == right || abs(left - right) == 1) return;

	if (left > right) {
		maxPQ.push(mid);

		mid = minPQ.top();
		minPQ.pop();
	}
	else {
		minPQ.push(mid);

		mid = maxPQ.top();
		maxPQ.pop();
	}
}

int ans() {
	if (minPQ.size() == maxPQ.size())
		return mid;
	// minPQ와 maxPQ의 size 차이가 1인 경우
	else {
		if (cnt / 2 == minPQ.size())
			return minPQ.top();
		return mid;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	while(N--) {
		int num;
		cin >> num;

		if (mid == MAX) mid = num;

		else if (num < mid)
			minPQ.push(num);
		else maxPQ.push(num);

		cnt++;

		balance();

		cout << ans() << "\n";
	}

	return 0;
}
