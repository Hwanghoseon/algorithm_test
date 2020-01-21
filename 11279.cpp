#include<iostream>
#include<queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int> q;
	int temp;
	while (n--) {
		cin >> temp;

		if (!temp && q.empty())
			cout << "0\n";
		else if (!temp) {
			cout << q.top() << "\n";
			q.pop();
		}
		else q.push(temp);
	}

	return 0;
}
