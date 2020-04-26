#include<iostream>
#include<cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int sum = 0;

	int T = 10;
	while (T--) {
		int n;
		cin >> n;

		if (sum + n <= 100) {
			sum += n;

			if (sum == 100)
				break;
		}
		else {
			if (abs(sum + n - 100) <= abs(sum - 100)) {
				sum += n;
				break;
			}
			else break;
		}
	}

	cout << sum;

	return 0;
}
