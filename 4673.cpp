#include<iostream>

using namespace std;

const int MAX = 10000 + 1;

int list[MAX];

void checkSelfnum() {
	for (int i = 1; i < MAX; i++) {
		int sum = 0;

		int temp = i;

		sum += temp;

		while (temp) {
			sum += (temp % 10);

			temp /= 10;
		}

		if(sum < MAX)
			list[sum]++;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	checkSelfnum();

	for (int i = 1; i < MAX; i++)
		if (!list[i])
			cout << i << "\n";

	return 0;
}
