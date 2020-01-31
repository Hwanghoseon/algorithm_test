#include<iostream>
#include<string>

using namespace std;

int main(void) {
	string str[100];
	int list[26];

	int n;
	int cnt = 0;
	bool flag = true;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> str[i];

	for (int i = 0; i < n; i++) {
		fill_n(list, 26, 1);
		flag = true;

		list[str[i][0] - 'a']--;

		for (int j = 1; j < str[i].size(); j++) {
			if (str[i][j - 1] != str[i][j]) {
				list[str[i][j] - 'a']--;

				if (list[str[i][j] - 'a'] == -1)
					flag = false;
			}
		}
		if (flag)
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}
