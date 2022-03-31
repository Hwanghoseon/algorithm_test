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

long long int gcd(long long int a, long long int b) {
	long long int c;

	while (b) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

long long int lcm(long long int a, long long int b) {
	return a * b / gcd(a, b);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long int A, B;
	cin >> A >> B;

	cout << lcm(A, B);

	return 0;
}
