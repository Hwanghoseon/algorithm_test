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

string first, second;

int solution() {
	while (true) {
		if (first.length() == second.length()) {
			if (first == second)
				return 1;
			else
				return 0;
		}

		char temp = second[second.length() - 1];

		second.pop_back();

		if (temp == 'B')
			reverse(second.begin(), second.end());
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> first >> second;

	cout << solution();

	return 0;
}
