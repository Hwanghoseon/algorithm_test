#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 1000000 + 1;

int list[MAX];
int N, K;
int cnt;

void input() {
	cin >> N >> K;

	fill(list, list + N + 1, 0);

	for (int i = 0; i < N; i++)
		cin >> list[i];

	sort(list, list + N);
}

void func() {
	int high, low, sum;
	high = N - 1;
	low = 0;
	cnt = 0;

	int before = 100000000 * 2;		// before = K - sum

	while(low < high) {
		int temp = list[low] + list[high];

		if (abs(K - temp) == before) cnt++;
		else if (abs(K - temp) < before) {
			before = abs(K - temp);

			cnt = 1;
		}

		if (K == temp) {
			low++;
			high--;
		}
		else if (temp > K)
			high--;
		else low++;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		input();

		func();

		cout << cnt << "\n";
	}

	return 0;
}
