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

int N;
set<int> s;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		s.insert(num);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	set<int>::iterator it;
	for (it = s.begin(); it != s.end(); it++)
		cout << *it << " ";

	return 0;
}
