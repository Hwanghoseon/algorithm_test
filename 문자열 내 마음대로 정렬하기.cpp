#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;
	
	for (int i = 0; i < strings.size(); i++) {
		for (int j = 0; j < strings.size() - 1 - i; j++) {
			if (strings[j][n] > strings[j + 1][n]) {
				string temp = strings[j];
				strings[j] = strings[j + 1];
				strings[j + 1] = temp;
			}
			else if(strings[j][n] == strings[j + 1][n])
				if (strings[j] > strings[j + 1]) {
					string temp = strings[j];
					strings[j] = strings[j + 1];
					strings[j + 1] = temp;
				}
		}
	}

	answer = strings;

	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> strings = { "sun", "bed", "car" };

	vector<string> result;

	result = solution(strings, 1);

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";

	return 0;
}
