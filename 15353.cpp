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

string BigNumAdd(string num1, string num2) {
	string result = "";
	int sum = 0;

	while (!num1.empty() || !num2.empty() || sum) {
		if (!num1.empty()) {
			sum += num1.back() - '0';

			num1.pop_back();
		}

		if (!num2.empty()) {
			sum += num2.back() - '0';

			num2.pop_back();
		}

		result += (sum % 10) + '0';
		sum /= 10;
	}

	reverse(result.begin(), result.end());

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string num1, num2;
	cin >> num1 >> num2;

	cout << BigNumAdd(num1, num2);

	return 0;
}
