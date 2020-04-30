#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cstring>

using namespace std;

const int MAX = 255 + 1;

void input() {
	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;

	getline(cin, s);

	int happy = 0;
	int sad = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ':') {
			if (i + 2 < MAX) {
				if (s[i + 1] == '-' && s[i + 2] == ')')
					happy++;
				else if (s[i + 1] == '-' && s[i + 2] == '(')
					sad++;
			}
		}
	}

	if (sad == 0 && happy == 0) cout << "none\n";
	else if (sad == happy) cout << "unsure\n";
	else if (happy > sad)cout << "happy\n";
	else cout << "sad\n";

	return 0;
}
