#include <string>
#include <vector>

using namespace std;

const int alpha = 26;

int solution(string name) {
	int answer = 0;

	int len = name.length();

	// 'A'가 아닌 알파벳의 갯수 (조작해야 하는 알파벳)
	int cnt = 0;

	for (int i = 0; i < len; i++)
		if (name[i] != 'A')
			cnt++;

	// 현재 커서의 위치
	int cur = 0;

	while (cnt) {
		for (int i = 0; ; i++) {
			if (name[(cur + i + len) % len] != 'A') {
				answer += i;

				cur = (cur + i + len) % len;

				int temp = name[cur] - 'A';
				temp = min(temp, alpha - temp);

				name[cur] = 'A';

				answer += temp;

				cnt--;

				break;
			}

			if (name[(cur - i + len) % len] != 'A') {
				answer += i;

				cur = (cur - i + len) % len;

				int temp = name[cur] - 'A';
				temp = min(temp, alpha - temp);

				name[cur] = 'A';

				answer += temp;

				cnt--;

				break;
			}
		}
	}

	return answer;
}
