#include<iostream>

using namespace std;

const int MAX = 100000;

int n;
long long sum = 0;
int list[MAX];

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> list[i];

		sum += list[i];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	long long result = 0;

	for (int i = 0; i < n; i++)
		result += (sum - list[i]) * list[i];

	result /= 2;

	cout << result;

	return 0;
}
