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

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	map<string, int> m;

	while (N--) {
		long long temp;
		cin >> temp;

		string num = to_string(temp);

		m[num]++;
	}

	vector<pair<int, string>> list;

	map<string, int>::iterator it;

	string idx;
	int cnt = 0;

	for (it = m.begin(); it != m.end(); it++) {
		if (it->second > cnt) {
			idx = (it->first);

			cnt = it->second;
		}
		else if (it->second == cnt) {
			long long firstNum = stol(idx);
			long long secondNum = stol(it->first);

			if (firstNum > secondNum) idx = it->first;
		}
	}

	cout << idx;

	return 0;
}
