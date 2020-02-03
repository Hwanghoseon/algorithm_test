#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 1; i <= n; i++)
		v[i - 1] = i;

	do {
		for (int i = 0; i < n; i++)
			cout << v[i] << " ";
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}
