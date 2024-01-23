#include <bits/stdc++.h>

using namespace std;

int cnt;
string s;

int main(void) {
    cin >> s;
    
    while(s.size()) {
        // 문자열이 "a" 일때  
        // substr(0, 2)는 오류가 발생X
        // substr(1, 2)는 오류 발생O
        // 즉 시작하는 위치가 범위를 벗어나면 오류가 발생한다고 한다.
        // 마지막 위치가 범위를 벗어나면 자동으로 마지막까지 추출
        if(s.size() >= 2 && s.substr(0,2) == "c=") {cnt++; s.erase(0,2);}
        else if(s.size() >= 2 && s.substr(0,2) == "c-") {cnt++; s.erase(0,2);}
        else if(s.size() >= 3 && s.substr(0,3) == "dz=") {cnt++; s.erase(0,3);}
        else if(s.size() >= 2 && s.substr(0,2) == "d-") {cnt++; s.erase(0,2);}
        else if(s.size() >= 2 && s.substr(0,2) == "lj") {cnt++; s.erase(0,2);}
        else if(s.size() >= 2 && s.substr(0,2) == "nj") {cnt++; s.erase(0,2);}
        else if(s.size() >= 2 && s.substr(0,2) == "s=") {cnt++; s.erase(0,2);}
        else if(s.size() >= 2 && s.substr(0,2) == "z=") {cnt++; s.erase(0,2);}
        else {cnt++; s.erase(0,1);}
    }
    cout << cnt;
}