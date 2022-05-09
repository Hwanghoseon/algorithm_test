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
#include<climits>

using namespace std;

int N, M;

void input() {
	string temp;
	cin >> temp;

	string num = "";

	for (int i = 0; i < temp.length(); i++) {
		if (temp[i] >= '0' && temp[i] <= '9')
			num += temp[i];
		else {
			N = stoi(num);

			num = "";
		}
	}
	M = stoi(num);
}

int gcd(int a, int b) {
	int c;

	while (b) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

void solution() {
	int temp = gcd(N, M);

	cout << N / temp << ":" << M / temp;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();

	return 0;
}
