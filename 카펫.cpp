#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> list;

	for (int i = 0; i < numbers.size(); i++) {
		string temp = "";

		while (numbers[i]) {
			temp += (char)((numbers[i] % 10) + '0');

			numbers[i] /= 10;
		}

		reverse(temp.begin(), temp.end());
		list.push_back(temp);
	}

	sort(list.begin(), list.end());
	reverse(list.begin(), list.end());

	for (int i = 0; i < list.size(); i++)
		answer += list[i];

	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> input = { 3, 30, 34, 5, 9 };

	cout << solution(input);

	return 0;
}
