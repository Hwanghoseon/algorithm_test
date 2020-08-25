#include<iostream>
#include<string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	cin >> input;

	for (int i = 0; i < input.length(); i++)
		if (input[i] != 'C' && input[i] != 'A' && input[i] != 'M' && input[i] != 'B' && input[i] != 'R' && input[i] != 'I' && input[i] != 'D' && input[i] != 'G' && input[i] != 'E')
			cout << input[i];

	return 0;
}
