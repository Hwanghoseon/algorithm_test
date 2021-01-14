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

int N;
vector<int> mNum;	// 음수
vector<int> pNum;	// 1을 제외한 양수
int zeroCnt = 0;
int oneCnt = 0;

bool desc(int a, int b) {
	return a > b;
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (num == 1) oneCnt++;
		else if (num == 0) zeroCnt++;
		else if (num < 0)
			mNum.push_back(num);
		else pNum.push_back(num);
	}

	sort(mNum.begin(), mNum.end());
	sort(pNum.begin(), pNum.end(), desc);
}

int sol() {
	int result = 0;

	// 음수
	for (int i = 0; i + 1 < mNum.size(); i += 2)
		result += (mNum[i] * mNum[i + 1]);

	// 음수의 갯수가 홀수인 경우
	if (mNum.size() % 2 && !zeroCnt)
		result += mNum[mNum.size() - 1];

	// 양수
	for (int i = 0; i + 1 < pNum.size(); i += 2)
		result += (pNum[i] * pNum[i + 1]);

	// 양수의 갯수가 홀수인 경우
	if (pNum.size() % 2)
		result += pNum[pNum.size() - 1];

	result += oneCnt;

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << sol();

	return 0;
}
