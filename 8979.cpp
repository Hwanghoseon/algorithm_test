#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Medal {
	int gold, silver, bronze;
};

const int MAX = 1000 + 1;

int n, m;
vector<pair<Medal, int>> country;
int checkGold, checkSilver, checkBronze;

void input() {
	cin >> n >> m;

	country.resize(MAX);

	for (int i = 1; i <= n; i++) {
		cin >> country[i].second >> country[i].first.gold >> country[i].first.silver >> country[i].first.bronze;

		if (country[i].second == m) {
			checkGold = country[i].first.gold;
			checkSilver = country[i].first.silver;
			checkBronze = country[i].first.bronze;
		}
	}
}

int func(){
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (country[i].second == m) continue;

		if (country[i].first.gold > checkGold) cnt++;
		else if (country[i].first.gold == checkGold && country[i].first.silver > checkSilver) cnt++;
		else if (country[i].first.gold == checkGold && country[i].first.silver == checkSilver && country[i].first.bronze > checkBronze) cnt++;
	}

	return cnt + 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << func();

	return 0;
}
