#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 500;

int costList[MAX];
int tempList[MAX];
int n;

int maxcost(int x) {
	cin >> tempList[0];

	costList[0] = tempList[0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++)
			tempList[j] = costList[j];

		for (int j = 0; j <= i; j++)
			cin >> costList[j];

		for (int j = 0; j <= i; j++) {
			if (j == 0)
				costList[j] += tempList[j];
			else if (j == i)
				costList[j] += tempList[j - 1];
			else
				costList[j] += max(tempList[j - 1], tempList[j]);
		}
	}

	int result = 0;

	for (int i = 0; i < n; i++)
		if (result < costList[i])
			result = costList[i];

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	cout << maxcost(n) << endl;

	return 0;
}
