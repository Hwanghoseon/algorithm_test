#include<iostream>

using namespace std;

const int MAX = 1000000 + 1;

long long minNum, maxNum;
long long list[MAX];

void preCalculate() {
	for (long long i = 2; i * i <= maxNum; i++) {
		long long temp = i * i;

		long long startNum = minNum / temp;

		if (minNum % temp) startNum++;

		while (startNum * temp <= maxNum) {
			list[startNum * temp - minNum]++;

			startNum++;
		}
	}
}

long long getCount() {
	long long cnt = maxNum - minNum + 1;

	for (long long i = 0; i <= maxNum - minNum; i++)
		if (list[i])
			cnt--;
	
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> minNum >> maxNum;

	preCalculate();

	cout << getCount();

	return 0;
}
