#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 4000;

int n;
int arr12Len;
int arr34Len;
int list[MAX][4];
vector<int> arr12;
vector<int> arr34;
long long sum = 0;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			cin >> list[i][j];

	// 첫번째와 두번째 배열의 합의 모든 경우와
	// 세번째와 네번째 배열의 합의 모든 경우를 저장한다.
	// 배열 4개를 모두 체크하면 시간초과 문제를 해결할 수 없다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sum12;
			int sum34;

			sum12 = list[i][0] + list[j][1];
			sum34 = list[i][2] + list[j][3];

			arr12.push_back(sum12);
			arr34.push_back(sum34);
		}
	}
	sort(arr12.begin(), arr12.end());
	sort(arr34.begin(), arr34.end());

	// = arr12.size();
	//arr34Len = arr34.size();
}

int lowerBinary(int low, int high, int target) {
	while (low < high) {
		int mid = (low + high) / 2;

		if (arr34[mid] >= target)
			high = mid;
		else low = mid + 1;
	}

	return high;
}

int upperBinary(int low, int high, int target) {
	if (arr34[high] == target)
		return n * n;

	while (low < high) {
		int mid = (low + high) / 2;

		if (arr34[mid] > target)
			high = mid;
		else low = mid + 1;
	}

	return high;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	for (int i = 0; i < n * n; i++) {
		int temp = 0 - arr12[i];

		sum += (upperBinary(0, arr34.size() - 1, temp) - lowerBinary(0, arr34.size() - 1, temp));
	}

	cout << sum;

	return 0;
}
