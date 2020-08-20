#include<iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int H, W, N;
		cin >> H >> W >> N;

		int result;

		if(N % H)
			result = (N % H) * 100 + ((N - 1) / H + 1);
		else result = H * 100 + ((N - 1) / H + 1);

		cout << result << "\n";
	}

	return 0;
}
