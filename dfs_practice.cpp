#include<iostream>
#include<vector>

using namespace std;

int number = 7;
bool check[7];
vector<int> con[8];

void dfs(int n) {
	if (check[n]) return;

	check[n] = true;
	cout << n << " ";

	for (int i = 0; i < con[n].size(); i++)
		dfs(con[n][i]);
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
