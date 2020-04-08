#include<iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int list[3] = { 300, 60, 10 };
	int result[3];

	int n;
	cin >> n;

	int temp;
	for (int i = 0; i < 3; i++) {
		temp = n / list[i];
		result[i] = temp;
		n -= temp * list[i];
	}

	if (n != 0) cout << "-1";
	else {
		for (int i = 0; i < 3; i++)
			cout << result[i] << " ";
	}
	return 0;
}
