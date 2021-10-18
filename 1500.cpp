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

const int MAX = 20;

int S, K;
long long list[MAX];

long long solution() {
	long long ans = 1;

	for (int i = 0; i < K; i++)
		list[i] = S / K;
	
	S %= K;

	for (int i = 0; S > 0; i++) {
		S--;

		list[i]++;
	}

	for(int i = 0; i < MAX; i++)
		if(list[i])
			ans *= list[i];

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> S >> K;

	cout << solution();

	return 0;
}
