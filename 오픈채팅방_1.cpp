#include <string>
#include <vector>
#include <map>

using namespace std;

const int MAX = 1e5;

struct User{
    string type, id, name;
};

map<string, string> m;

User split(string input){
    User user;
    
    if(input[0] == 'E' || input[0] == 'C'){
        string temp = "";
        
        int cnt = 0;
        for(int i = 0; i < input.length(); i++){
            if(input[i] != ' ')
                temp += input[i];
            else{
                if(cnt == 0){
                    user.type = temp;
                    
                    cnt++;
                }
                else if(cnt == 1)
                    user.id = temp;
                
                temp = "";
            }
        }
        user.name = temp;
    }
    else{
        string temp = "";
        
        int cnt = 0;
        for(int i = 0; i < input.length(); i++){
            if(input[i] != ' ')
                temp += input[i];
            else{
                if(cnt == 0)
                    user.type = temp;
                
                temp = "";
            }
        }
        user.id = temp;
    }
    
    return user;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<User> user;
    
    for(int i = 0; i < record.size(); i++){
        User temp = split(record[i]);
        
        if(temp.type != "Leave")
            m[temp.id] = temp.name;
        
        if(temp.type == "Change") continue;
        
        user.push_back(temp);
    }
    
    for(int i = 0; i < user.size(); i++){
        string temp = "";
        
        if(user[i].type == "Enter"){
            temp += m[user[i].id];
            temp += "님이 ";
            temp += "들어왔습니다.";
        }
        else if(user[i].type == "Leave"){
            temp += m[user[i].id];
            temp += "님이 ";
            temp += "나갔습니다.";
        }
        
        answer.push_back(temp);
    }
    
    return answer;
}
