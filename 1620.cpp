#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

const int MAX = 100000;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<string> name(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> name[i];

	vector<pair<string, int>> list(N);

	for (int i = 0; i < N; i++) {
		list[i].first = name[i + 1];
		list[i].second = i + 1;
	}
	sort(list.begin(), list.end());

	while (M--) {
		string input;
		cin >> input;

		// 입력으로 숫자가 들어왔을 경우
		if (input[0] >= '0' && input[0] <= '9') {
			int num = stoi(input);

			cout << name[num] << "\n";
		}
		// 입력으로 문자가 들어왔을 경우
		else {
			int low = 0;
			int high = N - 1;

			int mid;

			while (low <= high) {
				mid = (low + high) / 2;

				if (list[mid].first == input) {
					cout << list[mid].second << "\n";
					break;
				}
				else if (list[mid].first < input)
					low = mid + 1;
				else
					high = mid - 1;
			}
		}
	}

	return 0;
}
