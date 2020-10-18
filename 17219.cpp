#include<iostream>
#include<string>
#include<map>

using namespace std;

map<string, string> password;
int N, M;

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string ad, ps;
		cin >> ad >> ps;

		password[ad] = ps;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	for (int i = 0; i < M; i++) {
		string word;
		cin >> word;

		cout << password[word] << "\n";
	}

	return 0;
}
