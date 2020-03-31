#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 50;

int n;
vector<int> A;
vector<int> B;

bool desc(int a, int b) {
	return a > b;
}

void input() {
	cin >> n;

	A.resize(n);
	B.resize(n);

	for (int i = 0; i < n; i++)
		cin >> A[i];

	for (int i = 0; i < n; i++)
		cin >> B[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), desc);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += A[i] * B[i];

	cout << sum;

	return 0;
}
