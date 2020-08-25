#include<iostream>
#include<string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	cin >> input;

	int cntJ = 0;
	int cntI = 0;

	for (int i = 0; i < input.length() - 2; i++) {
		if (input[i] == 'J' && input[i + 1] == 'O' && input[i + 2] == 'I')
			cntJ++;
		else if (input[i] == 'I' && input[i + 1] == 'O' && input[i + 2] == 'I')
			cntI++;
	}

	cout << cntJ << "\n" << cntI;

	return 0;
}
