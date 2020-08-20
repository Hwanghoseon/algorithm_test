#include<iostream>
#include<string>
#include<cmath>

using namespace std;

const long long MOD = 1234567891;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int L;
	cin >> L;

	string input;
	cin >> input;

	long long result = 0;
	long long temp = 1;

	for (int i = 0; i < L; i++) {
		result = (result + (input[i] - 'a' + 1) * temp) % MOD;

		temp = (temp * 31) % MOD;
	}
	
	cout << result;

	return 0;
}
