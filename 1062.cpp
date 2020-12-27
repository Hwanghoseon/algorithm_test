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

using namespace std;

const int MAX = 26;

int N, K;
vector<string> word;
vector<char> list;
bool visited[MAX];
bool alpha[MAX];
int result = 0;

void input() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		string st;
		cin >> st;

		word.push_back(st);

		for (int j = 4; j < word[i].length() - 4; j++)
			alpha[word[i][j] - 'a'] = true;
	}

	// 'anta', 'tica'는 단어에 꼭 들어간다.
	alpha['a' - 'a'] = false;
	alpha['c' - 'a'] = false;
	alpha['i' - 'a'] = false;
	alpha['n' - 'a'] = false;
	alpha['t' - 'a'] = false;

	for (int i = 0; i < MAX; i++)
		if (alpha[i])
			list.push_back(i + 'a');

	alpha['a' - 'a'] = true;
	alpha['c' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;
}

int countWord() {
	int sum = N;
	bool temp[MAX] = { false , };

	temp['a' - 'a'] = true;
	temp['c' - 'a'] = true;
	temp['i' - 'a'] = true;
	temp['n' - 'a'] = true;
	temp['t' - 'a'] = true;

	for (int i = 0; i < list.size(); i++)
		if (visited[i])
			temp[list[i] - 'a'] = true;

	for(int i = 0; i < N; i++){
		for (int j = 4; j < word[i].length() - 4; j++) {
			if (!temp[word[i][j] - 'a']) {
				sum--;
				break;
			}
		}
	}

	return sum;
}

void func(int cnt, int idx) {
	if (cnt == K) {
		result = max(result, countWord());

		return;
	}

	if (idx == list.size()) return;

	// 선정
	visited[idx] = true;
	func(cnt + 1, idx + 1);

	// 선정X
	visited[idx] = false;
	func(cnt, idx + 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	int temp = list.size();

	if (temp <= (K - 5))
		result = N;
	else
		func(5, 0);

	cout << result;

	return 0;
}
