#include<iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int hour, minute;
	cin >> hour >> minute;

	if (minute >= 45)
		cout << hour << " " << minute - 45;
	else {	// 시간 단위가 바뀔경우
		minute += (60 - 45);

		if (hour >= 1)
			hour -= 1;
		else
			hour += (24 - 1);

		cout << hour << " " << minute;
	}
	
	return 0;
}
