#include<iostream>
#include<string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string A, B;
	cin >> A >> B;

	int N, M;
	bool check = false;
	for (int i = 0; i < A.length(); i++) {
		for (int j = 0; j < B.length(); j++)
			if (A[i] == B[j]) {
				N = i;
				M = j;
				check = true;
				break;
			}
		if (check) break;
	}


	for (int i = 0; i < B.length(); i++) {
		if (M == i) {
			cout << A << "\n";
			continue;
		}

		for (int j = 0; j < A.length(); j++) {
			if (N == j)
				cout << B[i];
			else
				cout << ".";
		}
		cout << "\n";
	}

	return 0;
}
