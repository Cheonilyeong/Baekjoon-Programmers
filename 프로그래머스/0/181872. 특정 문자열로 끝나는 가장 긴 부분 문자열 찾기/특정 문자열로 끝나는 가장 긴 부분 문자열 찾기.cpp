#include <bits/stdc++.h>

using namespace std;

string solution(string myString, string pat) {
    long long pos;
    string temp = myString;
    string ret = "";
    while((pos = temp.find(pat)) != string::npos) {
        ret += temp.substr(0, pos + pat.size());
        temp.erase(0, pos + pat.size());
    }
    return ret;
}