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

const int MAX = 1e6;

bool visited[MAX];
int A, P;

int solution() {
	vector<int> list;
	list.push_back(A);
	visited[A] = true;

	int N;

	// 수열 추가
	while (true) {
		N = 0;

		string temp = to_string(A);

		for (int i = 0; i < temp.length(); i++)
			N += pow(temp[i] - '0', P);

		if (visited[N]) break;

		list.push_back(N);
		visited[N] = true;
		A = N;
	}

	// 반복수열 제외
	while (list.back() != N)
		list.pop_back();

	list.pop_back();

	return list.size();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> P;

	cout << solution();

	return 0;
}
