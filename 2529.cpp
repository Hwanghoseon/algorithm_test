#include<iostream>
#include<cmath>
#include<climits>
#include<algorithm>
#include<string>

using namespace std;

const int MAX = 10;

int N;
int arr[MAX];
char list[MAX];
bool visited[MAX];
string resultMax = "0000000000";
string resultMin = "9999999999";

void input() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> list[i];
}

bool isPossible() {
	for (int i = 0; i < N; i++) {
		if (list[i] == '>') {
			if (arr[i] < arr[i + 1])
				return false;
		}
		else 
			if (arr[i] > arr[i + 1])
				return false;
	}

	return true;
}

string changeNum() {
	string sum = "";

	for (int i = 0; i < N + 1; i++)
		sum += to_string(arr[i]);

	return sum;
}

void func(int cnt) {
	if (cnt == N + 1) {
		if (isPossible()) {
			string temp = changeNum();

			resultMax = max(resultMax, temp);
			resultMin = min(resultMin, temp);

			return;
		}
		else return;
	}

	for (int i = 0; i < MAX; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt] = i;
			func(cnt + 1);
			visited[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func(0);

	cout << resultMax << "\n" << resultMin;

	return 0;
}
