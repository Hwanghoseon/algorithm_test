#include<iostream>
#include<queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int n;

void func() {
	cin >> n;

	while (n--) {
		int temp;
		cin >> temp;

		if (temp) pq.push(temp);
		else {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	func();

	return 0;
}
