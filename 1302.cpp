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
map<string, int> list;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string book;
		cin >> book;

		list[book]++;
	}
}

string solution() {
	map<string, int>::iterator it;

	string title;
	int cnt = 0;

	for(it = list.begin(); it != list.end(); it++)
		if (cnt < it->second) {
			title = it->first;
			cnt = it->second;
		}

	return title;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
