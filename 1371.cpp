#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

int alpha[26];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;

	while (cin >> input) {
		for (int i = 0; i < input.length(); i++)
			if (input[i] >= 'a' && input[i] <= 'z')
				alpha[input[i] - 'a']++;

		input.clear();
	}

	int maxCnt = 0;
	for (int i = 0; i < 26; i++)
		maxCnt = max(maxCnt, alpha[i]);

	for (int i = 0; i < 26; i++)
		if (alpha[i] == maxCnt)
			cout << (char)(i + 'a');

	return 0;
}
