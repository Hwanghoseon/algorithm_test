#include <string>
#include <map>

using namespace std;

const int NUM = 65536;

// 대문자로 통일
int solution(string str1, string str2) {
	int answer = 0;

	map<string, int> m;

	int cntStr = 0;
	for (int i = 0; i < str1.length() - 1; i++) {
		if (str1[i] >= 'a' && str1[i] <= 'z')
			str1[i] = (str1[i] - 'a') + 'A';

		if (str1[i + 1] >= 'a' && str1[i + 1] <= 'z')
			str1[i + 1] = (str1[i + 1] - 'a') + 'A';

		if ((str1[i] < 'A' || str1[i] > 'Z') || (str1[i + 1] < 'A' || str1[i + 1] > 'Z'))
			continue;

		string temp = "";
		temp += str1[i];
		temp += str1[i + 1];

		m[temp]++;
		cntStr++;
	}

	int cnt = 0;
	for (int i = 0; i < str2.length() - 1; i++) {
		if (str2[i] >= 'a' && str2[i] <= 'z')
			str2[i] = (str2[i] - 'a') + 'A';

		if (str2[i + 1] >= 'a' && str2[i + 1] <= 'z')
			str2[i + 1] = (str2[i + 1] - 'a') + 'A';

		if ((str2[i] < 'A' || str2[i] > 'Z') || (str2[i + 1] < 'A' || str2[i + 1] > 'Z'))
			continue;

		string temp = "";
		temp += str2[i];
		temp += str2[i + 1];

		if (m[temp]) {
			m[temp]--;

			cnt++;
		}
		cntStr++;
	}

	if (!(cntStr - cnt)) answer = 1 * NUM;
	else {
		double result = (double)cnt / (double)(cntStr - cnt);

		result *= NUM;

		answer = result;
	}

	return answer;
}
