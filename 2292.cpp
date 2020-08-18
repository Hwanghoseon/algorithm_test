#include<iostream>
#include<vector>

using namespace std;

const int MAX = 20000;

long long n;
vector<long long> list(MAX);

void func() {
	list[0] = 1;
	for (long long i = 1; i < MAX; i++)
		list[i] = i * 6;

	long long sum = 0;
	for (int i = 0; i < MAX; i++) {
		sum += list[i];

		if (sum >= n) {
			cout << i + 1;
			break;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	func();
	
	return 0;
}
