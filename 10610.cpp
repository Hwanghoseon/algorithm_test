#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string list;
int sum = 0;	// 모든 수의 합이 3의 배수인지 확인
bool isZero = false;
vector<int> arr;

bool desc(int a, int b) {
	return a > b;
}

void func() {
	for (int i = 0; i < list.length(); i++) {
		int temp = list[i] - '0';

		if (!temp) isZero = true;

		sum += temp;

		arr.push_back(temp);
	}

	if (isZero && !(sum % 3)) {
		sort(arr.begin(), arr.end(), desc);

		for (int i = 0; i < arr.size(); i++)
			cout << arr[i];
	}
	else cout << "-1";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> list;

	func();

	return 0;
}
