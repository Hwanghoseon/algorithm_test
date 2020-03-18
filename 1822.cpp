#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 500000;

int n, m;
int cnt = 0;
vector<int> arr;
vector<bool> visit;
//int visit[MAX];

void binarySearch(int low, int high, int target) {
	while (low <= high) {
		int mid = (low + high) / 2;

		if (arr[mid] == target) {
			visit[mid] = true;
			cnt++;
			return;
		}
		else if (arr[mid] > target)
			high = mid - 1;
		else low = mid + 1;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());

	visit.resize(n);

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;

		binarySearch(0, n - 1, temp);
	}

	// 다 없을 경우 0 출력
	if (cnt == n)
		cout << "0";
	else {
		cout << n - cnt << "\n";
		for (int i = 0; i < n; i++)
			if (!visit[i])
				cout << arr[i] << " ";
	}
	
	return 0;
}
