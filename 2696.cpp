#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int n;
		vector<int> list;
		vector<int> result;

		cin >> n;

		int cnt = 0;
		//list.resize(n);
		for (int i = 0; i < n; i++) {
			//cin >> list[i];
			int temp;
			cin >> temp;

			list.push_back(temp);

			if (list.size() % 2) {
				sort(list.begin(), list.end());

				cnt++;

				result.push_back(list[cnt - 1]);
			}
		}

		cout << result.size() << "\n";

		for (int i = 0; i < result.size(); i++)
			cout << result[i] << " ";
		cout << "\n";

		while(!result.empty()) result.pop_back();
	}

	return 0;
}
