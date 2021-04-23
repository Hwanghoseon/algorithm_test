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

const int MAX = 250 + 1;

string list[MAX];

string BigNumAdd(string num1, string num2) {
	string result = "";
	long long sum = 0;

	while (!num1.empty() || !num2.empty() || sum) {
		if (!num1.empty()) {
			sum += num1.back() - '0';

			num1.pop_back();
		}

		if (!num2.empty()) {
			sum += num2.back() - '0';

			num2.pop_back();
		}

		result.push_back((sum % 10) + '0');
		sum /= 10;
	}

	reverse(result.begin(), result.end());

	return result;
}

void func() {
	list[0] = "1";
	list[1] = "1";

	for (int i = 2; i < MAX; i++)
		list[i] = BigNumAdd(BigNumAdd(list[i - 2], list[i - 2]), list[i - 1]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	func();

	int N;

	while (cin >> N)
		cout << list[N] << "\n";

	return 0;
}
