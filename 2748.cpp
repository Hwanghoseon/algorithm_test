#include<iostream>

using namespace std;

const int MAX = 90 + 1;

long long a[MAX];

long long fib(int x) {
	a[0] = 0;
	a[1] = 1;

	for (int i = 0; i < x; i++)
		a[i + 2] = a[i + 1] + a[i];

	return a[x];
}

int main(void) {
	int n;
	cin >> n;

	cout << fib(n);

	return 0;
}
