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

int N, M;
vector<pair<string, int>> list;
string alpha[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

void input() {
	cin >> N >> M;

	for (int i = N; i <= M; i++) {
		string temp = "";

		if (i / 10) {
			temp += alpha[i / 10];
			temp += " ";
		}
		
		temp += alpha[i % 10];

		list.push_back({ temp, i });
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	sort(list.begin(), list.end());

	for (int i = 0; i < list.size(); i++) {
		cout << list[i].second << " ";

		if ((i + 1) % 10 == 0)
			cout << "\n";
	}

	return 0;
}
