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

const int MAX = 1e7;

vector<int> candidate;
int N;
bool visited[MAX];

void primeCheck() {
	for (int i = 2; i < sqrt(MAX); i++)
		for (int j = i * i; j < MAX; j += i)
			visited[j] = true;

	for (int i = 2; i < MAX; i++)
		if (!visited[i])
			candidate.push_back(i);
}

bool checkNum(string input) {
	for (int i = 0; i < input.length(); i++)
		if (input[i] != input[input.length() - i - 1])
			return false;

	return true;
}

int solution() {
	for (int i = 0; i < candidate.size(); i++) {
		if (candidate[i] < N) continue;

		string st = to_string(candidate[i]);

		if (checkNum(st)) return  candidate[i];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	primeCheck();

	cout << solution();

	return 0;
}
