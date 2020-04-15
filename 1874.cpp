#include<iostream>
#include<stack>
#include<vector>

using namespace std;

const int MAX = 100000 + 1;

int input[MAX];		// 입력 받을 수
int list[MAX];
vector<char> result;	// 부호 저장하기 위한 벡터

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> s;
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> input[i];

		list[i] = i;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		while (s.empty() || s.top() != input[i]) {
			cnt++;

			s.push(cnt);
			result.push_back('+');

			if (s.top() != input[i] && cnt > n) {
				cout << "NO\n";
				exit(0);
			}
		}

		if (s.top() == input[i]) {
			s.pop();
			result.push_back('-');
		}
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";

	return 0;
}
