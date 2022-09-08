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

string func(string input) {
	string ans = "";
	string temp = "";

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ' ') {
			reverse(temp.begin(), temp.end());

			ans += temp;
			ans += " ";
			temp = "";
		}
		else if (input[i] == '<') {
			reverse(temp.begin(), temp.end());

			ans += temp;
			temp = "";

			while (true) {
				ans += input[i++];

				if (input[i] == '>') {
					ans += input[i];

					break;
				}
			}
		}
		else
			temp += input[i];
	}

	if (temp != "") {
		reverse(temp.begin(), temp.end());

		ans += temp;
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;

	getline(cin, input);

	cout << func(input);

	return 0;
}
