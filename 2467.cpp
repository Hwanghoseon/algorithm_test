#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cstdio>

using namespace std;

const int MAX = 1e9 * 2 + 1;

int N;
vector<int> list;

void input() {
	cin >> N;

	list.resize(N);

	for (int i = 0; i < N; i++)
		cin >> list[i];
}

void func() {
	int low, high;

	low = 0;
	high = N - 1;

	int result = MAX;
	int resultList[2];

	while (low < high) {
		int temp = list[low] + list[high];

		if (abs(temp) < result) {
			result = abs(temp);

			resultList[0] = list[low];
			resultList[1] = list[high];
		}

		if (temp > 0)
			high--;
		else if (temp < 0)
			low++;
		else break;
	}

	cout << resultList[0] << " " << resultList[1];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func();

	return 0;
}
