#include<iostream>
#include<vector>

using namespace std;

vector<pair<pair<int, int>, int>> person;	// 몸무게, 키, 등수
int n;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int height, weight;
		cin >> height >> weight;

		person.push_back(make_pair(make_pair(height, weight), 1));
	}
}

void func() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;

			if (person[i].first.first < person[j].first.first && person[i].first.second < person[j].first.second)
				person[i].second++;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func();

	for (int i = 0; i < n; i++)
		cout << person[i].second << " ";

	return 0;
}
