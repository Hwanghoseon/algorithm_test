#include<iostream>
#include<algorithm>

using namespace std;

int n;
int firstNum, secondNum, thirdNum;
int bestdp[2][3];
int worstdp[2][3];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> firstNum >> secondNum >> thirdNum;

		if (i == 0) {
			bestdp[1][0] = worstdp[1][0] = firstNum;
			bestdp[1][1] = worstdp[1][1] = secondNum;
			bestdp[1][2] = worstdp[1][2] = thirdNum;
		}
		else {
			bestdp[1][0] = max(firstNum + bestdp[0][0], firstNum + bestdp[0][1]);
			worstdp[1][0] = min(firstNum + worstdp[0][0], firstNum + worstdp[0][1]);

			bestdp[1][1] = max(max(secondNum + bestdp[0][0], secondNum + bestdp[0][1]), secondNum + bestdp[0][2]);
			worstdp[1][1] = min(min(secondNum + worstdp[0][0], secondNum + worstdp[0][1]), secondNum + worstdp[0][2]);

			bestdp[1][2] = max(thirdNum + bestdp[0][1], thirdNum + bestdp[0][2]);
			worstdp[1][2] = min(thirdNum + worstdp[0][1], thirdNum + worstdp[0][2]);
		}

		for (int i = 0; i < 3; i++) {
			bestdp[0][i] = bestdp[1][i];
			worstdp[0][i] = worstdp[1][i];
		}
	}
	
	int maxCnt = max(max(bestdp[0][0], bestdp[0][1]), bestdp[0][2]);
	int minCnt = min(min(worstdp[0][0], worstdp[0][1]), worstdp[0][2]);

	cout << maxCnt << " " << minCnt;
	
	return 0;
}
