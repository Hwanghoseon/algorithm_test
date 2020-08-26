#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> list;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	list.resize(n);
	for (int i = 0; i < n; i++)
		cin >> list[i];

	for (int i = 0; i < n; i++) {
		string temp = list[i];
		reverse(temp.begin(), temp.end());

		for (int j = 0; j < n; j++) {
			if (list[j].compare(temp) == 0) {
				cout << list[j].size() << " " << list[j][list[j].length() / 2];
				return 0;
			}
		}
	}

	return 0;
}
