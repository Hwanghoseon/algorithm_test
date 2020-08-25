#include<iostream>
#include<string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		string input1, input2;
		cin >> input1 >> input2;

		cout << "Distances: ";
		for (int i = 0; i < input1.length(); i++) {
			int x = input1[i] - '0';
			int y = input2[i] - '0';

			if (y - x >= 0)
				cout << y - x << " ";
			else
				cout << y - x + 26 << " ";
		}
		cout << "\n";
	}

	return 0;
}
