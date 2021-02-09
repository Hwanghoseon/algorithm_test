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

int N;
vector<int> arr;
vector<int> list;
int share, rest;

void input() {
	cin >> N;

	arr.resize(N);
	list.resize(N - 1);
	
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	for (int i = 1; i < N; i++)
		list[i - 1] = arr[i] - arr[i - 1];

	sort(list.begin(), list.end());
}

int gcd(int a, int b) {
	int c;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	
	share = gcd(list[0], list[1]);

	for (int i = 2; i < list.size(); i++) 
		share = gcd(share, list[i]);
	
	vector<int> result;

	for (int i = 2; i * i <= share; i++) {
		if (share % i == 0) {
			result.push_back(i);
			result.push_back(share / i);
		}
	}
	result.push_back(share);

	sort(result.begin(), result.end());

	int before = -1;

	for (int i = 0; i < result.size(); i++) {
		if (before == result[i]) continue;

		cout << result[i] << " ";

		before = result[i];
	}

	return 0;
}
