#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>

using namespace std;

const int MAX = 50;

int N, M;
int map[MAX][MAX];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
bool visited[13];
int result = INT_MAX;

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1)
				house.push_back(make_pair(i, j));
			else if (map[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}
}

void func(int cnt, int idx) {
	if (cnt == M) {
		int sum = 0;

		for (int i = 0; i < house.size(); i++) {
			int dist = INT_MAX;

			for (int j = 0; j < chicken.size(); j++)
				if (visited[j])
					dist = min(dist, (abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second)));

			sum += dist;
		}

		result = min(result, sum);

		return;
	}

	/*for (int i = idx; i < chicken.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			func(cnt + 1, num + 1);
			visited[i] = false;
		}
	}*/

	if (idx == chicken.size()) return;

	// 선정
	visited[idx] = true;
	func(cnt + 1, idx + 1);
	// 선정 X
	visited[idx] = false;
	func(cnt, idx + 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func(0, 0);

	cout << result;

	return 0;
}
