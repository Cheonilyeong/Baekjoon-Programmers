#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int todayY = atoi(today.substr(0, 4).c_str());
    int todayM = atoi(today.substr(5, 2).c_str());
    int todayD = atoi(today.substr(8, 2).c_str());
    
    cout << "today : " << todayY << "." << todayM << "." << todayD << '\n';
    map<char,int> t;
    for(string s : terms) {
        t[s[0]] = atoi(s.substr(2).c_str());
    }
    
    for(int i = 0; i < privacies.size(); i++) {
        string s = privacies[i];
        
        int year = atoi(s.substr(0, 4).c_str());
        int month = atoi(s.substr(5, 2).c_str());
        int day = atoi(s.substr(8, 2).c_str());
        char p = s.back();
        
        cout << "p : " << year << "." << month << "." << day << " t[p]" << t[p] << " -> ";
        
        month += t[p];
        while(month > 12) {
            year++;
            month -= 12;
        }
        
        cout << "t : " << year << "." << month << "." << day << '\n';
        
        if(year == todayY && month == todayM && day <= todayD) answer.push_back(i+1);
        if(year == todayY && month < todayM) answer.push_back(i+1);
        if(year < todayY) answer.push_back(i+1);
    }

    return answer;
}