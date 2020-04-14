#include<iostream>
#include<cstring>

using namespace std;

const int MAX = 1000 + 1;

int n;
int person[MAX];
bool visit[MAX];
int cnt = 0;

void input() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;

		person[i] = temp;
	}
}

void func(int x) {
	if (visit[x]) return;

	visit[x] = true;
	cnt++;

	if (!visit[person[x]])
		func(person[x]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	int result = 0;
	int resultPerson = 0;
	for (int i = 1; i <= n; i++) {
		cnt = 0;

		memset(visit, false, sizeof(visit));

		func(i);

		if (result < cnt) {
			resultPerson = i;
			result = cnt;
		}
	}

	cout << resultPerson;

	return 0;
}




