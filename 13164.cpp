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
vector<int> list;
vector<int> gap;

bool desc(int a, int b) {
	return a > b;
}

void input() {
	cin >> N >> M;

	list.resize(N);

	for (int i = 0; i < N; i++)
		cin >> list[i];

	sort(list.begin(), list.end());
}

int solution() {
	for (int i = 0; i < N - 1; i++) 
		gap.push_back(list[i + 1] - list[i]);

	gap.push_back(0);
	gap.push_back(0);

	sort(gap.begin(), gap.end());

	M--;
	while (M--)
		gap.pop_back();

	int ans = 0;
	for (int i = 0; i < gap.size(); i++)
		ans += gap[i];

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
