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

int N, C;
vector<pair<pair<int, int>, int>> list;	// cnt, idx, num
map<int, int> cntList;	// num, cnt
map<int, int> idxList;	// num, idx

void input() {
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		if (!cntList[temp])
			idxList[temp] = N - i;

		cntList[temp]++;
	}
}

void solution() {
	map<int, int>::iterator it;

	for (it = cntList.begin(); it != cntList.end(); it++)
		list.push_back({ {it->second, idxList[it->first]}, it->first });

	sort(list.begin(), list.end());
	
	vector<int> result;

	for (int i = 0; i < list.size(); i++)
		for (int j = 0; j < list[i].first.first; j++)
			result.push_back(list[i].second);

	reverse(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();

	return 0;
}
