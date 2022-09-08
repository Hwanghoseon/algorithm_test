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

int solution(string input) {
	set<string> list;

	for (int i = 0; i < input.length(); i++) {
		string temp = "";
		for (int j = i; j < input.length(); j++) {
			temp += input[j];

			list.insert(temp);
		}
	}

	return list.size();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	cin >> input;

	cout << solution(input);

	return 0;
}
