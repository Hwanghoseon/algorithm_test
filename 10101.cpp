#include<iostream>

using namespace std;

int a, b, c;
int sum = 0;

void input() {
	cin >> a >> b >> c;

	sum = a + b + c;
}

void resultPrint() {
	if (sum != 180) {
		cout << "Error";
		return;
	}
	if (a == 60 && b == 60 && c == 60) {
		cout << "Equilateral";
		return;
	}
	if (a == b || b == c || c == a) {
		cout << "Isosceles";
		return;
	}
	cout << "Scalene";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	resultPrint();

	return 0;
}
