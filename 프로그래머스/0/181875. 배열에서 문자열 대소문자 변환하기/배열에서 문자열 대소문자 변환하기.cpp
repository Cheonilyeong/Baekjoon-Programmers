#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    for(int i = 0; i < strArr.size(); i++) {
        string input = "";
        if(i & 1) {
            for(char c : strArr[i]) input += toupper(c);
            answer.push_back(input);
        }
        else {
            for(char c : strArr[i]) input += tolower(c);
            answer.push_back(input);
        }
    }
    return answer;
}