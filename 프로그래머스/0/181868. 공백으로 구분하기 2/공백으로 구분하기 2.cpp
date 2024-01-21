#include <bits/stdc++.h>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> ret;
    string temp = "";
    for(char c : my_string) {
        if(c == ' ' && temp.size()) {
            ret.push_back(temp);
            temp = "";
        }
        else if(c != ' ') temp += c;
    }
    if(temp.size()) ret.push_back(temp);
    return ret;
}