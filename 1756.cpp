#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 300000 + 1;

int N, M;
int list[MAX];	// 오븐

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	// 오븐 크기 입력
	int before = 1000000000 + 1;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];

		before = min(before, list[i]);
		
		list[i] = before;
	}

	int idx = N + 1;
	int result = 0;

	while (M--) {
		int pizza;
		cin >> pizza;

		while (idx) {
			idx--;

			if (list[idx] >= pizza) {
				if(!M) result = idx;

				break;
			}
		}
	}

	cout << result;

	return 0;
}
