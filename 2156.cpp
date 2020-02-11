#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 10001;

int n;
int check[MAX];
int maxDrink[MAX];

void input() {
	for (int i = 1; i <= n; i++)
		cin >> check[i];
}

void Dp() {
	maxDrink[1] = check[1];
	maxDrink[2] = maxDrink[1] + check[2];

	for (int i = 3; i <= n; i++) {
		maxDrink[i] = max(maxDrink[i - 2] + check[i], maxDrink[i - 3] + check[i - 1] + check[i]);
		maxDrink[i] = max(maxDrink[i], maxDrink[i - 1]);	// 두번 건너뛰거나 마지막을 안먹을 경우
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	input();

	Dp();

	int max = 0;

	cout << maxDrink[n];

	return 0;
}
