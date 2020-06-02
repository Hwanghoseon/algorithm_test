#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX = 1000;

int cache[MAX][MAX];
string s1, s2;

void input() {
	cin >> s1 >> s2;
}

int LCS(int idx1, int idx2) {
	// 문자열의 범위 벗어날 경우
	if (idx1 == s1.length() || idx2 == s2.length())
		return 0;

	int &result = cache[idx1][idx2];

	if (result != -1) return result;

	// s1 인덱스가 증가했을 경우
	// s2 인덱스가 증가했을 경우
	// s1, s2  인덱스 모두 증가했을 경우
	return result = max(LCS(idx1 + 1, idx2), max(LCS(idx1, idx2 + 1), LCS(idx1 + 1, idx2 + 1) + (s1[idx1] == s2[idx2])));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	memset(cache, -1, sizeof(cache));

	cout << LCS(0, 0);

	return 0;
}
