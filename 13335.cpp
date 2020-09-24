#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num, len, weight;
	cin >> num >> len >> weight;

	vector<int> list(num);

	for (int i = 0; i < num; i++)
		cin >> list[i];

	queue<int> truck;
	int sum = 0;
	int second = 0;

	for (int i = 0; i < num; i++) {
		while (true) {
			if (truck.size() == len) {
				sum -= truck.front();
				truck.pop();
			}

			if (sum + list[i] <= weight) break;

			truck.push(0);
			second++;
		}
		truck.push(list[i]);
		sum += list[i];
		second++;
	}

	second += len;

	cout << second;

	return 0;
}
