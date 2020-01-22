#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int number = 7;
bool check[7];
vector<int> con[8];

void dfs(int start) {
	stack<int> s;
	s.push(start);
	check[start] = true;
	cout << start << " ";

	while (!s.empty()) {
		int current_node = s.top();
		s.pop();

		for (int i = 0; i < con[current_node].size(); i++) {
			int next_node = con[current_node][i];

			if (!check[next_node]) {
				check[next_node] = true;
				cout << next_node << " ";
				s.push(current_node);
				s.push(next_node);
				break;
			}
		}
	}
}

int main(void) {
	con[1].push_back(2);
	con[2].push_back(1);

	con[1].push_back(3);
	con[3].push_back(1);

	con[2].push_back(3);
	con[3].push_back(2);

	con[2].push_back(4);
	con[4].push_back(2);

	con[2].push_back(5);
	con[5].push_back(2);

	con[3].push_back(6);
	con[6].push_back(3);

	con[3].push_back(7);
	con[7].push_back(3);

	con[4].push_back(5);
	con[5].push_back(4);

	con[6].push_back(7);
	con[7].push_back(6);

	dfs(1);

	return 0;
}
