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

int gcd(int a, int b) {
	int c;

	while (b) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	cout << M - gcd(N, M);

	return 0;
}
