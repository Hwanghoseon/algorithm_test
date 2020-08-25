#include<iostream>
#include<string>

using namespace std;

const int MAX = 1000000 + 1;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char result[MAX];

	string input, boom;
	cin >> input >> boom;

	int idx = 0;
	for (int i = 0; i < input.length(); i++) {
		result[idx++] = input[i];

		if (result[idx - 1] == boom[boom.length() - 1]) {
			if (idx - boom.length() < 0) continue;

			bool isExist = true;
			for (int j = 0; j < boom.length(); j++) {
				if (result[idx - j - 1] != boom[boom.length() - j - 1]) {
					isExist = false;
					break;
				}
			}

			if (isExist)
				idx -= boom.length();
		}
	}

	if (!idx) cout << "FRULA";
	else
		for (int i = 0; i < idx; i++)
			cout << result[i];

	return 0;
}
