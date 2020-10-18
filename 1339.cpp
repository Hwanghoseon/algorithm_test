#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

const int ALPHA = 26;
const int MAX = 10;

int N;
int alphabet[ALPHA];
vector<int> alpha;

bool desc(int a, int b) {
	return a > b;
}

void input() {
	cin >> N;

	string word;

	for (int i = 0; i < N; i++) {
		cin >> word;

		for (int j = 0; j < word.length(); j++)
			alphabet[word[j] - 'A'] += pow(10, word.length() - j - 1);
	}

	for (int i = 0; i < ALPHA; i++)
		if (alphabet[i])
			alpha.push_back(alphabet[i]);

	sort(alpha.begin(), alpha.end(), desc);
}

int func() {
	int sum = 0;

	for (int i = 0; i < alpha.size(); i++)
		sum += alpha[i] * (9 - i);

	return sum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << func();

	return 0;
}
