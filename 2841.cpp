#include<iostream>
#include<vector>

using namespace std;

const int MAX = 500000;

int n, p;
vector<int> melody[MAX];

int func() {
	int cnt = 0;

	cin >> n >> p;

	for (int i = 0; i < n; i++) {
		int sound, fret;
		cin >> sound >> fret;
		
		if (melody[sound].empty() || melody[sound].back() < fret) {
			melody[sound].push_back(fret);
			cnt++;
		}
		else if (melody[sound].back() == fret) continue;
		else if (melody[sound].back() > fret) {
			while (true) {
				melody[sound].pop_back();
				cnt++;

				if (melody[sound].empty() || melody[sound].back() < fret) {
					melody[sound].push_back(fret);
					cnt++;
					break;
				}
				else if (melody[sound].back() == fret) break;
			}
		}
	}
	
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << func() << "\n";

	return 0;
}
