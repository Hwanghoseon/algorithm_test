#include<iostream>
#include<deque>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	deque<int> dq;

	int len, n;
	cin >> len >> n;

	for (int i = 1; i <= len; i++)
		dq.push_back(i);

	int temp, value, size;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		cin >> temp;

		size = dq.size();
		int subcount = 0;

		while (dq.front() != temp) {
			value = dq.front();
			dq.pop_front();
			dq.push_back(value);
			subcount++;
		}

		dq.pop_front();

		if (subcount <= size / 2)
			count += subcount;
		else count += (size - subcount);
	}

	cout << count << endl;

	return 0;
}
