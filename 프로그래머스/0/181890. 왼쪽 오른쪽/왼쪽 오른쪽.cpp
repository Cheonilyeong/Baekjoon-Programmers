#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> str_list) {
    vector<string> answer;
    for(int i = 0; i < str_list.size(); i++) {
        if(str_list[i] == "l") {
            for(int j = 0; j < i; j++) {
                answer.push_back(str_list[j]);
            }
            return answer;
        }
        else if(str_list[i] == "r") {
            for(int j = i + 1; j < str_list.size(); j++) {
                answer.push_back(str_list[j]);
            }
            return answer;
        }
    }
    return answer;
}