#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	int list[26] = { 0 };	//알파벳 배열

	for (int i = 0; i < str.length(); i++)
		for (int j = 65; j <= 90; j++)
			if (str[i] == j || str[i] == j + 32)
				list[j - 65]++;

	int max = 0;
	int max_alph = 0;
	bool check = true;

	for (int i = 0; i < 26; i++) {
		if (list[i] > max) {
			max = list[i];
			max_alph = i;
			check = true;
		}
		else if (list[i] == max)
			check = false;
	}

	char ch = 'A' + max_alph;

	if (!check)
		cout << "?" << endl;
	else
		cout << ch << endl;

	return 0;
}
