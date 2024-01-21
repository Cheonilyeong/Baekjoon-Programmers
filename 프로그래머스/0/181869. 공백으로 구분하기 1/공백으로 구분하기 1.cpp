#include <bits/stdc++.h>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> ret;
    long long pos;
    string temp = "";
    while((pos = my_string.find(" ")) != string::npos) {
        temp = my_string.substr(0, pos);
        my_string.erase(0, pos + 1);
        ret.push_back(temp);
    }
    ret.push_back(my_string);
    return ret;
}