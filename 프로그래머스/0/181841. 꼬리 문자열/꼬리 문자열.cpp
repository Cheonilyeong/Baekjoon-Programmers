#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> str_list, string ex) {
    string answer = "";
    for(string str : str_list) {
        long long pos;
        if((pos = str.find(ex)) == string::npos)
            answer += str;
    }
    return answer;
}