#include <string>
#include <vector>

using namespace std;

const int MAX = 100;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;

	for (int i = 0; i < arr1.size(); i++) {
		vector<int> list;

		for (int j = 0; j < arr2[0].size(); j++) {
			int temp = 0;

			for (int k = 0; k < arr1[i].size(); k++) {
				temp += (arr1[i][k] * arr2[k][j]);
			}

			list.push_back(temp);
		}
		answer.push_back(list);

		list.clear();
	}

	return answer;
}
