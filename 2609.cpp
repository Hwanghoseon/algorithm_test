#include<iostream>

using namespace std;

int gcd(int a, int b) {
	int c;

	while (b) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num1, num2;
	cin >> num1 >> num2;

	cout << gcd(num1, num2) << "\n" << lcm(num1, num2);
	
	return 0;
}
