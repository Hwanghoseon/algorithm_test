// 연속적인 값을 체크해야하기 때문에
// 슬라이딩 윈도우 사용

#include<iostream>
#include<cstring>

using namespace std;

const long long MAX = 4000000 + 1;

bool isDecimal[MAX];	// 소수 여부 확인

void checkDecimal(long long n) {
	memset(isDecimal, true, sizeof(isDecimal));

	isDecimal[0] = isDecimal[1] = false;

	for (long long i = 2; i <= n; i++)
		for (long long j = i * i; j <= n; j += i)
			isDecimal[j] = false;
}

int numberCase(int n) {
	int low = 0;
	int high = 0;
	int sum = 0;
	int cnt = 0;

	while (true) {
		if (sum >= n) {
			while (!isDecimal[low]) low++;

			sum -= (low++);
		}
		else if (high >= n + 1) break;
		else if (sum < n) {
			while (!isDecimal[high]) high++;

			sum += (high++);
		}

		if (sum == n) cnt++;
	}

	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;

	// 소수에는 1을 저장한다.
	checkDecimal(n);

	cout << numberCase(n);

	return 0;
}
