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

int N, cnt = 0;
char op[] = { '+', ' ', '-' };
vector<string> s;

bool checkSum(string st) {
	int sum = 0;
	char c = '+';
	string temp = "";

	for (int i = 0; i < st.length(); i++) {
		if (st[i] > '0' && st[i] <= '9') temp += st[i];
		else if (st[i] == ' ') continue;
		else {
			if (c == '+')
				sum += stoi(temp);
			else
				sum -= stoi(temp);

			temp = "";
			c = st[i];
		}
	}

	if (c == '+')
		sum += stoi(temp);
	else
		sum -= stoi(temp);

	if (!sum) return true;
	return false;
}

void bt(int idx, string st) {
	if (idx == N) {
		if (checkSum(st))
			//cout << st << "\n";
			s.push_back(st);
			
		return;
	}

	for (int i = 0; i < 3; i++)
		bt(idx + 1, st + op[i] + to_string(idx + 1));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		cin >> N;

		s.clear();

		bt(1, "1");

		sort(s.begin(), s.end());

		for (int i = 0; i < s.size(); i++)
			cout << s[i] << "\n";

		cout << "\n";
	}

	return 0;
}
