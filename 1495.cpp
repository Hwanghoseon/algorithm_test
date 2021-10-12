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

const int MAX = 100 + 1;
const int MAXV = 1000 + 1;

int N, S, M;
int playlist[MAX];
int cache[MAXV][MAX];

void input() {
	cin >> N >> S >> M;

	for (int i = 1; i <= N; i++)
		cin >> playlist[i];
}

int maxVolume(int volume, int idx) {
	if (volume < 0 || volume > M) return -100;

	if (idx == N)
		return volume;

	int &result = cache[volume][idx];
	if (result != -1)
		return result;

	return result = max(maxVolume(volume + playlist[idx + 1], idx + 1), maxVolume(volume - playlist[idx + 1], idx + 1));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	memset(cache, -1, sizeof(cache));

	int result = maxVolume(S, 0);

	if (result == -100) result = -1;

	cout << result;

	return 0;
}
