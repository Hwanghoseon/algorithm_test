#include<iostream>
#include<string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string num1, num2;
	cin >> num1 >> num2;

	int sizeNum1 = num1.length();
	int sizeNum2 = num2.length();
	string result = "";

	bool flag = false;	// 합이 10이 넘는지 확인
	for (int i = 0; i < sizeNum1 && i < sizeNum2; i++) {
		int checkSum = num1[sizeNum1 - i - 1] - '0' + num2[sizeNum2 - i - 1] - '0';
		if (flag) checkSum++;

		if (checkSum >= 10) {
			flag = true;
			checkSum -= 10;
		}
		else flag = false;
		result += (checkSum + '0');
	}

	if (sizeNum1 > sizeNum2) {
		for (int i = 0; i < sizeNum1 - sizeNum2; i++) {
			int checkSum = num1[sizeNum1 - sizeNum2 - i - 1] - '0';

			if (flag) checkSum++;

			if (checkSum >= 10) {
				flag = true;
				checkSum -= 10;
			}
			else flag = false;
			result += (checkSum + '0');
		}
	}
	else if (sizeNum1 < sizeNum2) {
		for (int i = 0; i < sizeNum2 - sizeNum1; i++) {
			int checkSum = num2[sizeNum2 - sizeNum1 - i - 1] -'0';

			if (flag) checkSum++;

			if (checkSum >= 10) {
				flag = true;
				checkSum -= 10;
			}
			else flag = false;
			result += (checkSum + '0');
		}
	}

	if (flag) result += '1';

	for (int i = 0; i < result.length(); i++) {
		cout << result[result.length() - 1 - i];
	}

	return 0;
}
