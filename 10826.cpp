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

const int MAX = 1e5 + 1;

int N;
string list[MAX];

string bigNumAdd(string num1, string num2) {
	long long sum = 0;
	string result = "";

	while (!num1.empty() || !num2.empty() || sum) {
		if (!num1.empty()) {
			sum += num1.back() - '0';

			num1.pop_back();
		}

		if (!num2.empty()) {
			sum += num2.back() - '0';

			num2.pop_back();
		}

		result.push_back(sum % 10 + '0');
		sum /= 10;
	}

	reverse(result.begin(), result.end());
	
	return result;
}

void func() {
	list[0] = "0";
	list[1] = "1";

	for (int i = 2; i < N + 1; i++)
		list[i] = bigNumAdd(list[i - 2], list[i - 1]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	func();

	cout << list[N];

	return 0;
}
