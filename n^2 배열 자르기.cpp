#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
	vector<int> answer;

	long long row = left / n + 1;
	long long col = left % n + 1;
	long long temp = col;
	bool isFull = false;

	for (int i = row; i <= n; i++) {
		int k = temp;
		for (k; k <= i; k++) {
			answer.push_back(i);

			left++;

			if (left > right) isFull = true;

			if (isFull) break;
		}

		if (isFull) break;

		for (k; k <= n; k++) {
			answer.push_back(k);

			left++;

			if (left > right) isFull = true;

			if (isFull) break;
		}
		if (isFull) break;

		col = i + 1;
		temp = 1;
	}

	return answer;
}
