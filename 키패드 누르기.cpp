#include <string>
#include <vector>

using namespace std;

const int MAX = 100;

int length[MAX][MAX];

void distanceCheck() {
	// '*'
	length['*'][0] = 1;
	length['*'][1] = 3;
	length['*'][4] = 2;
	length['*'][7] = 1;

	length['*'][2] = 4;
	length['*'][5] = 3;
	length['*'][8] = 2;

	// '#'
	length['#'][2] = 4;
	length['#'][5] = 3;
	length['#'][8] = 2;
	length['#'][0] = 1;

	length['#'][3] = 3;
	length['#'][6] = 2;
	length['#'][9] = 1;

	for (int i = 1; i < 10; i++)
		for (int j = 1; j < 10; j++)
			length[i][j] = abs((i - 1) / 3 - (j - 1) / 3) + abs((i- 1) % 3 - (j - 1) % 3);

	for (int i = 1; i < 10; i++) 
		length[i][0] = length[0][i] = abs(10 / 3 - (i - 1) / 3) + abs(10 % 3 - (i - 1) % 3);
}

string solution(vector<int> numbers, string hand) {
	string answer = "";

	distanceCheck();

	int leftNow = '*';
	int rightNow = '#';

	for (int i = 0; i < numbers.size(); i++) {
		// 왼손 범위일 경우
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
			leftNow = numbers[i];
			answer += "L";

			continue;
		}
		// 오른손 범위일 경우
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			rightNow = numbers[i];
			answer += "R";

			continue;
		}

		// 왼손 오른손 모두 올 수 있는 범위일 경우
		int leftDistance = length[leftNow][numbers[i]];
		int rightDistance = length[rightNow][numbers[i]];

		if (leftDistance > rightDistance) {

			rightNow = numbers[i];
			answer += "R";
		}
		else if (leftDistance < rightDistance) {
			leftNow = numbers[i];
			answer += "L";
		}
		// 거리가 같은 결우
		else {
			// 왼손잡이
			if (hand == "left") {
				leftNow = numbers[i];
				answer += "L";
			}
			// 오른손 잡이
			else {
				rightNow = numbers[i];
				answer += "R";
			}
		}
	}

	return answer;
}
