#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> v;

void printPrev() {
	if (prev_permutation(v.begin(), v.end()))
		for (int i = 0; i < n; i++)
			cout << v[i] << " ";
	else cout << "-1";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	printPrev();

	return 0;
}
