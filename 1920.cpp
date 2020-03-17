#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 100000;

int n, m;
vector<int> arr;

int binarySearch(int low, int high, int target) {
	// low가 high보다 클 경우
	if (low > high) return 0;

	else {
		int mid = (low + high) / 2;

		// 해당 지점에 target이 있다면 찾았으므로 1 반환
		if (arr[mid] == target) return 1;
		// 해당 지점에 있는 수가 target보다 크면 왼쪽 반 탐색
		else if (arr[mid] > target)
			return binarySearch(low, mid - 1, target);
		// 해당 지점에 있는 수가 target보다 작으면 오른쪽 반 탐색
		else
			return binarySearch(mid + 1, high, target);
	}
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

		cout << binarySearch(0, n - 1, temp) << "\n";
	}
	
	return 0;
}
