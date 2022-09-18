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

vector<pair<string, string>> list;	// 생년월일, 이름
int N;

void input() {
	cin >> N;

	list.resize(N);

	for (int i = 0; i < N; i++) {
		string name, day, month, year;
		cin >> name >> day >> month >> year;

		if (month.length() == 1)
			month = "0" + month;

		list[i].first = year + month + day;
		list[i].second = name;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	sort(list.begin(), list.end());

	cout << list[N - 1].second << "\n" << list[0].second;

	return 0;
}
