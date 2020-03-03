#include<iostream>
#include<string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	bool flag = true;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != str[str.length() - i - 1]) {
			flag = false;
			break;
		}
	}

	if (flag) cout << "1";
	else cout << "0";
	
	return 0;
}
