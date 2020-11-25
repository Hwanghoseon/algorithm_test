#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<cstdio>

using namespace std;

typedef struct {
	string type, id, name;
}S;

S split(string input) {
	S s;

	char strType[20];
	char strId[20];
	char strName[20];

	if (input[0] == 'E' || input[0] == 'C') {
		sscanf(input.c_str(), "%s %s %s", strType, strId, strName);

		s.type = strType;
		s.id = strId;
		s.name = strName;
	}
	else {
		sscanf(input.c_str(), "%s %s", strType, strId);

		s.type = strType;
		s.id = strId;
	}

	return s;
}

vector<string> solution(vector<string> record) {
	vector<string> answer;

	// 유저 아이디 저장
	map<string, string> id;

	S s[100000];

	// 유저 아이디의 최종 닉네임 저장
	for (int i = 0; i < record.size(); i++) {
		s[i] = split(record[i]);

        if(s[i].type == "Enter" || s[i].type == "Change")
		    id[s[i].id] = s[i].name;
	}

	for (int i = 0; i < record.size(); i++) {
		string str = "";

		if (s[i].type == "Enter") {
			str += (id[s[i].id]);
			str += "님이 들어왔습니다.";

			answer.push_back(str);
		}
		else if (s[i].type == "Leave") {
			str += (id[s[i].id]);
			str += "님이 나갔습니다.";

			answer.push_back(str);
		}
	}

	return answer;
}
