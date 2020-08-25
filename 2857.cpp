#include<iostream>
#include<string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bool isExist = false;

	int list[6] = { 0, };
	for (int i = 1; i <= 5; i++) {
		string input;
		cin >> input;

		if (input.find("FBI") >= 0 && input.find("FBI") < input.length()) {
			isExist = true;

			list[i] = 1;
		}
	}

	if (!isExist) cout << "HE GOT AWAY!";
	else {
		for (int i = 1; i <= 5; i++)
			if(list[i])
				cout << i << " ";
	}

	return 0;
}
