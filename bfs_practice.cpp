#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int number = 7;
bool check[7];   //방문 check
vector<int> con[8];   // 각 노드 처리를 위해 

void bfs(int start) {
	queue<int> node;
	node.push(start);
	check[start] = true;

	while (!node.empty()) {
		int temp = node.front();
		node.pop();
		cout << temp << " ";

		for (int i = 0; i < con[temp].size(); i++) {
			if (!check[con[temp][i]]) {
				node.push(con[temp][i]);
				check[con[temp][i]] = true;
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

	bfs(1);

	return 0;
}
