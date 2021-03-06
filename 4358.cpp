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

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	string input;
	float cnt = 0;

	map<string, int> tree;

	while (getline(cin, input)) {
		tree[input]++;

		cnt++;
	}

	map<string, int>::iterator it;

	cout << fixed;
	cout.precision(4);
	for (it = tree.begin(); it != tree.end(); it++) {
		float temp = (it->second / cnt) * 100;

		cout << it->first << " " << temp << "\n";
	}

	return 0;
}
