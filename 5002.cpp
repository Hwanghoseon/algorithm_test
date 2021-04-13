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

int X;
string input;

int solution() {
	cin >> X >> input;

	int gap = 0;	// M - W
	int i = 0;

	// M는 +1, W는 -1
	for (i = 0; i < input.length(); i++) {
		if (input[i] == 'M' && abs(gap + 1) <= X)
			gap++;
		else if(input[i] == 'W' && abs(gap - 1) <= X)
			gap--;
		// 범위를 벗어날 경우
		else if ((input[i] == 'M' && input[i + 1] == 'W') || input[i] == 'W' && input[i + 1] == 'M')
			i++;
		else break;
	}

	return i;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << solution();
	
	return 0;
}
