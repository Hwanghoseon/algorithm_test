#include<iostream>

using namespace std;

int fibonacci(int x) {
	if (x == 0) return 0;
	else if (x == 1) return 1;
	else return fibonacci(x - 2) + fibonacci(x - 1);
}

int main(void) {
	int n;
	cin >> n;

	int result = fibonacci(n);

	cout << result;

	return 0;
}
