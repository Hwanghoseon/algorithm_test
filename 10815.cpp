#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 500000;

int n, m;
vector<int> arr;

int binarySearch(int low, int high, int target) {
	/*if (low > high) return 0;
	else {
		int mid = (low + high) / 2;
		if (arr[mid] == target)
			return 1;
		else if (arr[mid] > target)
			return binarySearch(low, mid - 1, target);
		else return binarySearch(mid + 1, high, target);
	}*/

	while (low <= high) {
		int mid = (low + high) / 2;

		if (arr[mid] == target) return 1;
		else if (arr[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;

		cout << binarySearch(0, n - 1, temp) << " ";
	}

	return 0;
}
