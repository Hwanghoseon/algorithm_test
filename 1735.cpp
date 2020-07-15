#include<iostream>

using namespace std;

// Numerator - 분자  denominator - 분모
int num1_Numerator, num1_Denominator, num2_Numerator, num2_Denominator;

int gcd(int a, int b) {
	int c;

	while (b) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

void func() {
	cin >> num1_Numerator >> num1_Denominator >> num2_Numerator >> num2_Denominator;

	int firstNum = num1_Denominator;
	int secondNum = num2_Denominator;

	num1_Numerator *= secondNum;
	num1_Denominator *= secondNum;

	num2_Numerator *= firstNum;
	num2_Denominator *= firstNum;

	int sum_Numerator, sum_Denominator;
	sum_Numerator = num1_Numerator + num2_Numerator;
	sum_Denominator = num1_Denominator;

	int common = gcd(sum_Numerator, sum_Denominator);

	cout << sum_Numerator / common << " " << sum_Denominator / common;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	func();

	return 0;
}
