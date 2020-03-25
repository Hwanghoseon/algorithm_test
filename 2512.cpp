#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 1000000000;

int n, m;
int low = 0;
int high;
vector<int> asset;
vector<int> result;

bool desc(int a, int b) {
	return a > b;
}

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		asset.push_back(temp);
	}

	cin >> m;

	sort(asset.begin(), asset.end());
	high = asset[n - 1];
}

bool check(int num) {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		if (asset[i] >= num)
			sum += num;
		else
			sum += asset[i];
	}

	if (sum <= m) {
		result.push_back(num);
		return true;
	}
	return false;
}

void binarySearch(int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;

		if (check(mid)) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	binarySearch(low, high);

	sort(result.begin(), result.end(), desc);

	cout << result[0];

	return 0;
}
