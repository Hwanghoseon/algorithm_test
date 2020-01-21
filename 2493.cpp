#include<iostream>
#include<stack>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	stack<pair<int, int>> s;

	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;

		if (s.empty()) {
			s.push({ i, temp});
			cout << "0 ";
		}
		else if (s.top().second < temp) {
			while (!s.empty() && s.top().second < temp)
				s.pop();
			
			if (s.empty()) {
				s.push({ i, temp });
				cout << "0 ";
			}
			else {
				cout << s.top().first << " ";
				s.push({ i, temp });
			}
		}
		else if (s.top().second >= temp) {
			cout << s.top().first << " ";
			s.push({ i, temp });
		}
	}

	return 0;
}
