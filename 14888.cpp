#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

const int MAX = 11;

int list[MAX];
char op[MAX];
char opArr[MAX];
char opList[4] = { '+', '-', '*', '/' };
bool visited[MAX];
int N;
int resultMin = INT_MAX;
int resultMax = INT_MIN;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> list[i];

	int cnt = 0;
	// op 갯수 입력
	for (int i = 0; i < 4; i++) {
		int temp;
		cin >> temp;

		for (int j = 0; j < temp; j++) {
			op[cnt] = opList[i];

			cnt++;
		}
	}
}

int getSum() {
	int sum = list[0];

	for (int i = 0; i < N - 1; i++) {
		if (opArr[i] == '+')
			sum += list[i + 1];
		else if (opArr[i] == '-')
			sum -= list[i + 1];
		else if (opArr[i] == '*')
			sum *= list[i + 1];
		else if (opArr[i] == '/')
			sum /= list[i + 1];
	}

	return sum;
}

void func(int cnt) {
	if (cnt == N - 1) {
		int sum = getSum();

		resultMax = max(resultMax, sum);
		resultMin = min(resultMin, sum);

		return;
	}

	for (int i = 0; i < N - 1; i++) {
		if (!visited[i]) {
			visited[i] = true;
			opArr[cnt] = op[i];
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
