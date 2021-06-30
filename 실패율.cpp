#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 500 + 2;

int list[MAX];
vector<pair<double, int>> v;
priority_queue<pair<double, int>> pq;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	for (int i = 0; i < stages.size(); i++)
		list[stages[i]]++;

	int temp = stages.size();

	for (int i = 1; i <= N; i++) {
		// v.push({list[i] / temp, N - i});

	    // temp -= list[i];

		if (!temp) {
			pq.push({ 0, N - i });

			continue;
		}

		pq.push({ (double)list[i] / (double)temp, N - i});

		temp -= list[i];
	}

	while (!pq.empty()) {
		answer.push_back(N - pq.top().second);

		pq.pop();
	}

	return answer;
}
