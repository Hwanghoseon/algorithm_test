#include<iostream>

using namespace std;

int A, B;

int func() {
	int cnt = 1;

	while (true) {
		cnt++;

		// B가 홀수일 경우
		if (B % 2) {
			if(B % 10 == 1)
				B /= 10;
			else return -1;
		}
		// B가 짝수일 경우
		else {
			B /= 2;
		}

		if (B == A) return cnt;
		else if (B < A) return -1;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> A >> B;

	cout << func();

	return 0;
}
