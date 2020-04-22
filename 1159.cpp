#include<iostream>
#include<string>

using namespace std;

const int MAX = 'z' - 'a' + 1;

int alpha[MAX];
int n;
bool flag = false;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		alpha[s[0] - 'a']++;

		if (alpha[s[0] - 'a'] >= 5) flag = true;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	for (int i = 0; i < MAX; i++) {
		if (!flag) {
			cout << "PREDAJA";
			break;
		}
		if (alpha[i] >= 5)
			cout << char('a' + i);
	}

	return 0;
}
