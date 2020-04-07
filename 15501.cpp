#include<iostream>
#include<queue>

using namespace std;

const int MAX = 1000000;

int list[MAX];	// 고정
int arr[MAX];
int n;
int start;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> list[i];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		if (arr[i] == list[0])
			start = i;
	}
}

int func() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {	// 정방향
		if (i + start < n) {
			if (list[i] == arr[i + start])
				cnt++;
		}
		else {
			if (list[i] == arr[i + start - n])
				cnt++;
		}
	}

	if (cnt == n) return 1;
	
	cnt = 0;

	for (int i = 0; i < n; i++) {	// 역방향
		if (start - i >= 0) {
			if (list[i] == arr[start - i])
				cnt++;
		}
		else {
			if (list[i] == arr[start - i + n])
				cnt++;
		}
	}

	if (cnt == n) return 1;

	return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	if (func()) cout << "good puzzle";
	else cout << "bad puzzle";

	return 0;
}
