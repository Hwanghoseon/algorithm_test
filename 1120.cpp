#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a;
	string b;

	cin >> a >> b;

	int cnt = 51;
	for (int i = 0; i <= b.length() - a.length(); i++) {
		int temp = 0;
		for (int j = 0; j < a.length(); j++) {
			if (b[j + i] != a[j]) temp++;
		}

		cnt = min(cnt, temp);
	}

	cout << cnt;

	return 0;
}
