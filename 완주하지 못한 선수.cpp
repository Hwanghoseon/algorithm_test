#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;

	map<string, int>::iterator it;
	
	for (int i = 0; i < participant.size(); i++) {
		if (m.find(participant[i]) == m.end())
			m.insert(make_pair(participant[i], 1));
		else m[participant[i]]++;
	}

	for (int i = 0; i < completion.size(); i++) {
		m[completion[i]]--;

		if (!m[completion[i]]) m.erase(completion[i]);
	}

	string answer = "";

	answer = m.begin()->first;

	return answer;
}
