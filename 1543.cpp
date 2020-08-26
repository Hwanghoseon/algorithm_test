#include<iostream>
#include<string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	string word;

	getline(cin, input);
	getline(cin, word);

	int cnt = 0;

	if (word.length() > input.length())
		cout << 0;
	else {
		for (int i = 0; i < input.length() - word.length() + 1; i++) {
			bool check = true;
			for (int j = 0; j < word.length(); j++) {
				if (input[i + j] != word[j]) {
					check = false;
					break;
				}
			}
			if (!check) continue;

			cnt++;
			i += word.length() - 1;
		}

		cout << cnt;
	}

	return 0;
}
