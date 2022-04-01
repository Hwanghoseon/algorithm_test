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

const int MAX = 100;

int alpha[MAX];
string input;

string solution() {
	for (int i = 0; i < input.length(); i++)
		alpha[input[i]]++;

	deque<char> list;
	string ans = "";

	for (int i = 'A'; i <= 'Z'; i++)
		if (alpha[i] % 2) {
			list.push_back(i);

			alpha[i]--;
		}

	if (list.size() > 1) {
		ans = "I'm Sorry Hansoo";

		return ans;
	}

	for (int i = 'Z'; i >= 'A'; i--) {
		while (alpha[i]) {
			list.push_front(i);
			list.push_back(i);

			alpha[i] -= 2;
		}
	}

	while (!list.empty()) {
		ans.push_back(list.front());

		list.pop_front();
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> input;

	cout << solution();

	return 0;
}
