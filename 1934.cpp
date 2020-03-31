#include<iostream>

using namespace std;

int gcd(int a, int b) {
	int c;

	while (b != 0) {
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

	int T;
	cin >> T;

	int num1, num2;
	while (T--) {
		cin >> num1 >> num2;
		
		cout << lcm(num1, num2) << "\n";
	}

	return 0;
}
