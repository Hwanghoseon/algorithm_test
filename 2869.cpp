#include<iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int B, A, V;
	cin >> B >> A >> V;

	V -= B;
	int gap = B - A;

	int day = 1;
	if (V % gap == 0)
		day += (V / gap);
	else
		day += (V / gap + 1);

	cout << day;

	return 0;
}
