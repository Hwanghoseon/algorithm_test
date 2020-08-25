#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string X, Y;
	cin >> X >> Y;

	int alpha[26] = { 0, };

	for (int i = 0; i < X.length(); i++)
		alpha[X[i] - 'a']++;

	for (int i = 0; i < Y.length(); i++)
		alpha[Y[i] - 'a']--;

	int cnt = 0;
	for (int i = 0; i < 26; i++)
		cnt += abs(alpha[i]);

	cout << cnt;

	return 0;
}
