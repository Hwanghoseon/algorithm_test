#include<iostream>
#include<algorithm>

using namespace std;

int mincost(int n) {
	int RGB[3];
	int temp[3];
	int red, green, blue;

	cin >> red >> green >> blue;

	RGB[0] = red, RGB[1] = green, RGB[2] = blue;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++)
			temp[j] = RGB[j];

		cin >> red >> green >> blue;

		RGB[0] = red + min(temp[1], temp[2]);
		RGB[1] = green + min(temp[0], temp[2]);
		RGB[2] = blue + min(temp[0], temp[1]);
	}

	return (RGB[0] < RGB[1] ? RGB[0] : RGB[1]) < RGB[2] ? (RGB[0] < RGB[1] ? RGB[0] : RGB[1]) : RGB[2];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> num;

	cout << mincost(num) << endl;

	return 0;
}
