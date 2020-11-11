#include<iostream>

using namespace std;

long long pow(long long A, long long B, long long C) {
	if (B == 1)
		return A;

	long long temp = pow(A, B / 2, C);

	// B / 2가 홀수인 경우는  +1
	if (B % 2)
		return temp * temp % C * A % C;
	return temp * temp % C;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long A, B, C;
	cin >> A >> B >> C;

	cout << pow(A % C, B, C);

	return 0;
}
