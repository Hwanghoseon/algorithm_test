#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 500 + 1;

int board[MAX][MAX];

int solution(vector<vector<int>> triangle) {
	int answer = 0;

	for (int i = 0; i < triangle.size(); i++)
		for (int j = 0; j < triangle[i].size(); j++)
			board[i + 1][j + 1] = triangle[i][j];

	int len = triangle.size();

	for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= i; j++) {
			board[i][j] = max(board[i][j] + board[i - 1][j], board[i][j] + board[i - 1][j - 1]);
		}
	}
	
	for (int i = 1; i <= len; i++)
		answer = max(answer, board[len][i]);

	return answer;
}
