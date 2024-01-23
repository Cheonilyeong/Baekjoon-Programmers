#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
    int answer = 0, pos;
    for(string s : order) {
        if((pos = s.find("americano")) != string::npos) 
            answer += 4500;
        else if((pos = s.find("cafelatte")) != string::npos)
            answer += 5000;
        else if(s == "anything")
            answer += 4500;
    }
    return answer;
}