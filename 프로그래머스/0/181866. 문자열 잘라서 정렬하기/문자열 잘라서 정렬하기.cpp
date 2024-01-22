#include <bits/stdc++.h>

using namespace std;

vector<string> solution(string myString) {
    vector<string> ret;
    long long pos;
    string temp;
    while((pos = myString.find('x')) != string::npos) {
        temp = myString.substr(0, pos);
        myString.erase(0, pos + 1);
        if(pos != 0) ret.push_back(temp);
    }
    if(myString.size()) ret.push_back(myString);
    sort(ret.begin(), ret.end());
    return ret;
}