#include <bits/stdc++.h>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string temp = "";
    for(int i = 0; i < my_string.size(); i++) {
        temp = my_string.substr(i, my_string.size() - i);
        answer.push_back(temp);
    }
    sort(answer.begin(), answer.end());
    return answer;
}