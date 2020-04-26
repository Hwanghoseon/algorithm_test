#include<iostream>
#include<string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s1, s2;	// 두 수
	cin >> s1 >> s2;

	string tempMax = "";
	string tempMin = "";
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == '5' || s1[i] == '6') {
			tempMax += "6";
			tempMin += "5";
		}
		else {
			tempMax += s1[i];
			tempMin += s1[i];
		}
	}

	// 최댓값과 최솟값
	int s1_max = stoi(tempMax);
	int s1_min = stoi(tempMin);

	tempMax = "";
	tempMin = "";
	for (int i = 0; i < s2.length(); i++) {
		if (s2[i] == '5' || s2[i] == '6') {
			tempMax += "6";
			tempMin += "5";
		}
		else {
			tempMax += s2[i];
			tempMin += s2[i];
		}
	}

	// 최댓값과 최솟값
	int s2_max = stoi(tempMax);
	int s2_min = stoi(tempMin);

	cout << s1_min + s2_min << " " << s1_max + s2_max;

	return 0;
}
