#include<iostream>

using namespace std;

int n;
int white[6] = { 1, 2, 3, 3, 4, 10 };	// 간달프 군대
int black[7] = { 1, 2, 2, 2, 3, 5, 10 };	// 사우론 군대
int whiteSum = 0;
int blackSum = 0;

void input() {
	int temp;
	whiteSum = 0;
	blackSum = 0;

	for (int i = 0; i < 6; i++) {
		cin >> temp;

		whiteSum += (white[i] * temp);
	}

	for (int i = 0; i < 7; i++) {
		cin >> temp;

		blackSum += (black[i] * temp);
	}
}

void printResult(int n) {
	if (whiteSum > blackSum)
		cout << "Battle " << n << ": Good triumphs over Evil" << "\n";
	else if(whiteSum == blackSum)
		cout << "Battle " << n << ": No victor on this battle field" << "\n";
	else
		cout << "Battle " << n << ": Evil eradicates all trace of Good" << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	
	for (int i = 1; i <= T; i++) {
		input();

		printResult(i);
	}

	return 0;
}
