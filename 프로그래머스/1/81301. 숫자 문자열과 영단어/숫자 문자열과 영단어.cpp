#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    string t = "";
    
    for(int i = 0; i < s.size(); i++) {
        if(isalpha(s[i])) {
            if(s.substr(i,3) == "one") {t += "1"; i += 2;}
            else if(s.substr(i,3) == "two") {t += "2"; i += 2;}
            else if(s.substr(i,3) == "six") {t += "6"; i += 2;}
            else if(s.substr(i,4) == "zero") {t += "0"; i += 3;}
            else if(s.substr(i,4) == "four") {t += "4"; i += 3;}
            else if(s.substr(i,4) == "five") {t += "5"; i += 3;}
            else if(s.substr(i,4) == "nine") {t += "9"; i += 3;}
            else if(s.substr(i,5) == "three") {t += "3"; i += 4;}
            else if(s.substr(i,5) == "seven") {t += "7"; i += 4;}
            else if(s.substr(i,5) == "eight") {t += "8"; i += 4;}
        }
        else {
            t += s[i];
        }
    }
    
    cout << t;
    return atoi(t.c_str());
}