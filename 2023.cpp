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
queue<string> q;
vector<string> result;
char list[5] = { '1', '3', '5', '7', '9' };

bool isPrime(string input){
	int num = stoi(input);

	int maxNum = (int)sqrt(num);

	for (int i = 2; i <= maxNum; i++)
		if (num % i == 0)
			return false;

	return true;
}

void solution() {
	q.push("2");
	q.push("3");
	q.push("5");
	q.push("7");

	while (!q.empty()) {
		string curNum = q.front();
		q.pop();

		if (curNum.length() == N) {
			result.push_back(curNum);

			continue;
		}

		for (int i = 0; i < 5; i++) {
			string nextNum = curNum + list[i];

			if (isPrime(nextNum)) q.push(nextNum);
		}
	}

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	solution();

	return 0;
}
