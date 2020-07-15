#include<iostream>
#include<deque>

using namespace std;

const int MAX = 5000000;

int N, L;
int arr[MAX];
deque<pair<int, int>> dq;	// value, idx

void slidingWindow() {
	cin >> N >> L;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	// dq에 정렬하면서 값을 저장
	for (int i = 0.; i < N; i++) {
		// dq의 제일 작은 값이 범위 안에 있는지 확인
		if (!dq.empty() && dq.front().second < i - L + 1)
			dq.pop_front();
		// arr[i]의 값보다 큰 수는 필요 없기 때문에 pop
		while (!dq.empty() && dq.back().first > arr[i])
			dq.pop_back();

		dq.push_back(make_pair(arr[i], i));
		cout << dq.front().first << " ";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	slidingWindow();

	return 0;
}
