#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 1000;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	vector<string> v;
	v.resize(str.length());

	for (int i = 0; i < str.length(); i++)
		for (int j = i; j < str.length(); j++)
			v[i] += str[j];

	sort(v.begin(), v.end());

	for (int i = 0; i < str.length(); i++)
		cout << v[i] << "\n";

	return 0;
}
