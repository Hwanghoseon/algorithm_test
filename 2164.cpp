#include<iostream>
#include<queue>

using namespace std;

int main() {
	queue<int> queue;

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		queue.push(i);

	while (true) {
		int temp;

		if (queue.size() != 1)
			queue.pop();
		else break;

		if (queue.size() != 1) {
			temp = queue.front();
			queue.push(temp);
			queue.pop();
		}
		else break;
	}

	cout << queue.front() << endl;

	return 0;
}
