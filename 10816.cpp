#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 500000;

int n, m;
vector<int> arr;

int upperBound(int target) {
	int start, end;
	start = 0;
	end = n - 1;

	// upperBound는 해당 수 보다 하나 더 큰 수의 위치를 저장하기 때문에
	// 배열의 범위를 넘어서는 경우를 따로 처리해준다.
	if (arr[end] == target)
		return n;

	while (start < end) {
		int mid = (start + end) / 2;

		if (arr[mid] > target)
			end = mid;
		else start = mid + 1;
	}
	
	return end;
}

int lowerBound(int target) {
	int start, end;
	start = 0;
	end = n - 1;

	while (start < end) {
		int mid = (start + end) / 2;

		if (arr[mid] >= target)
			end = mid;
		else start = mid + 1;
	}

	return end;
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

		cout << upperBound(temp) - lowerBound(temp) << " ";
	}

	return 0;
}
