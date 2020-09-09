#include<iostream>
#include<queue>

using namespace std;

const int MAX = 1000000;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		priority_queue<pair<int, int>> maxHeap;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
		bool visit[MAX] = { 0, };

		int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			char op;
			int num;
			cin >> op >> num;

			if (op == 'I') {
				maxHeap.push(make_pair(num, i));
				minHeap.push(make_pair(num, i));
				visit[i] = true;
			}
			// op == D
			else {
				// 최댓값 삭제
				if (num == 1) {
					while (!maxHeap.empty() && !visit[maxHeap.top().second]) maxHeap.pop();

					if (!maxHeap.empty()) {
						visit[maxHeap.top().second] = false;

						maxHeap.pop();
					}
				}
				// 최솟값 삭제
				else {
					while (!minHeap.empty() && !visit[minHeap.top().second]) minHeap.pop();

					if (!minHeap.empty()) {
						visit[minHeap.top().second] = false;

						minHeap.pop();
					}
				}
			}
		}
		while (!maxHeap.empty() && !visit[maxHeap.top().second]) maxHeap.pop();
		while (!minHeap.empty() && !visit[minHeap.top().second]) minHeap.pop();

		if (maxHeap.empty()) cout << "EMPTY\n";
		else{
			cout << maxHeap.top().first << " " << minHeap.top().first << "\n";
		}
	}

	return 0;
}
