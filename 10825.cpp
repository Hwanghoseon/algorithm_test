#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cstdio>
#include<climits>

using namespace std;

int N;

struct NAME {
	int a, b, c;
	string name;
};

vector<NAME> student;

bool compare(NAME n1, NAME n2) {
	if (n1.a > n2.a) 
		return true;
	else if (n1.a == n2.a) {
		if (n1.b < n2.b) 
			return true;
		else if (n1.b == n2.b) {
			if (n1.c > n2.c) 
				return true;
			else if (n1.c == n2.c) {
				if (n1.name < n2.name) 
					return true;
			}
		}
	}

	return false;
}

void input() {
	cin >> N;

	string name;
	int x, y, z;

	student.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> name >> x >> y >> z;

		student[i] = { x, y, z, name };
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	sort(student.begin(), student.end(), compare);

	for (int i = 0; i < N; i++)
		cout << student[i].name << "\n";

	return 0;
}
