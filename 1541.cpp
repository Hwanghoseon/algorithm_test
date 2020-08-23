#include<iostream>
#include<string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	cin >> input;

	int sum = 0;
	bool isPlus = true;
	string num;
	
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '+') {
			if (isPlus) sum += stoi(num);
			else sum -= stoi(num);

			num = "";
		}
		else if (input[i] == '-') {
			if (isPlus) {
				sum += stoi(num);

				isPlus = false;
			}
			else sum -= stoi(num);

			num = "";
		}
		else {
			num += input[i];
		}
	}

	if (isPlus) sum += stoi(num);
	else sum -= stoi(num);

	cout << sum;

	return 0;
}
