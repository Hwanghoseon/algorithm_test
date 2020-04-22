#include<iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long N;
	cin >> N;

	long long result = 0;
	for (long long i = 0; ; i++) {
		if (result + i > N) {
			cout << i - 1;
			break;
		}
		result += i;
	}

	return 0;
}
