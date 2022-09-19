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
vector<pair<pair<int, int>, string>> list;	//	길이, 각 자리수의 합, 시리얼 번호

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;

		int len = temp.length();
		int sum = 0;

		for (int j = 0; j < temp.length(); j++)
			if (temp[j] >= '0' && temp[j] <= '9')
				sum += temp[j] - '0';

		list.push_back({ {len, sum}, temp });
	}
}

void solution() {
	sort(list.begin(), list.end());

	for (int i = 0; i < N; i++)
		cout << list[i].second << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();

	return 0;
}
