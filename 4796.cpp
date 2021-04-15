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

int L, P, V;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; ; i++) {
		cin >> L >> P >> V;

		if (!L && !P && !V) break;

		int x = V / P;
		int y = V % P;

		int day = x * L + min(y, L);

		cout << "Case " << i << ": " << day << "\n";
	}

	return 0;
}
