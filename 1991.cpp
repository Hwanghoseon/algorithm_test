#include<iostream>
#include<vector>

using namespace std;

const int MAX = 26;

int n;
vector<pair<int, bool>> tree[MAX];

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;

		if (b != '.')
			tree[a - 'A'].push_back(make_pair(b - 'A', true));
		if (c != '.')
			tree[a - 'A'].push_back(make_pair(c - 'A', false));
	}
}

void preOrder(int node) {
	cout << (char)(node + 'A');

	for (int i = 0; i < tree[node].size(); i++)
		preOrder(tree[node][i].first);
}

void inOrder(int node) {
	// 자식이 존재하고 왼쪽 자식일 경우
	if (tree[node].size() && tree[node][0].second)
		inOrder(tree[node][0].first);
	cout << (char)(node + 'A');

	// 오른쪽 자식만 있을 경우
	if (tree[node].size() && !tree[node][0].second)
		inOrder(tree[node][0].first);
	// 양쪽 자식 다 있을 경우
	else if (tree[node].size() == 2)
		inOrder(tree[node][1].first);
}

void postOrder(int node) {
	for (int i = 0; i < tree[node].size(); i++)
		postOrder(tree[node][i].first);
	
	cout << (char)(node + 'A');
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	preOrder(0);
	cout << "\n";
	inOrder(0);
	cout << "\n";
	postOrder(0);
	cout << "\n";

	return 0;
}
