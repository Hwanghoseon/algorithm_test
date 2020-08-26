#include<iostream>
#include<string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, S;
	string input;

	cin >> N >> S >> input;

	int result = 0;
	int cnt = 0;
	for (int i = 1; i < input.length() - 1; i++) {
		if (input[i - 1] == 'I' && input[i] == 'O' && input[i + 1] == 'I') {
			cnt++;
			i++;
		}
		else {
			if (cnt) {
				int temp = cnt - N + 1;

				if (temp >= 0) result += temp;
				cnt = 0;
			}
		}
	}

	if (cnt) {
		int temp = cnt - N + 1;

		if (temp >= 0) result += temp;
		cnt = 0;
	}

	cout << result;

	return 0;
}
