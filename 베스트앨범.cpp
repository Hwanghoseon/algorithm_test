#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

const int MAX = 100;

//vector<pair<int, int>> list;
priority_queue<pair<int, int>> pq[MAX];
priority_queue<pair<int, int>> cntNum;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	map<string, int> m;

	for (int i = 0; i < genres.size(); i++)
		m[genres[i]] += plays[i];

	map<string, int>::iterator it;

	int cnt = 0;
	for (it = m.begin(); it != m.end(); it++) {
		cntNum.push({it->second, cnt});

		cnt++;

	}

	for (int i = 0; i < plays.size(); i++) {
		int cnt = 0;

		for (it = m.begin(); it != m.end(); it++) {
			if (genres[i] == it->first) {
				pq[cnt].push({ plays[i], genres.size() - i });

				break;
			}

			cnt++;
		}
	}

	while (!cntNum.empty()) {
		int cnt = 2;
		while (!pq[cntNum.top().second].empty() && cnt--) {
			answer.push_back(genres.size() - pq[cntNum.top().second].top().second);

			pq[cntNum.top().second].pop();
		}

		cntNum.pop();
	}
    
    return answer;
}
