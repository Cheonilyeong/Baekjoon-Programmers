#include <bits/stdc++.h>

using namespace std;

string solution(string a, string b) {
    string answer = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int up = 0, i, j;
    
    for(i = 0, j = 0; i < a.size() && j < b.size(); i++, j++) {
        if(up + (a[i] - '0') + (b[j] - '0') >= 10) {
            answer += to_string((up + (a[i] - '0') + (b[j] - '0')) % 10);
            up = 1;
        }
        else {
            answer += to_string((up + (a[i] - '0') + (b[j] - '0')));
            up = 0;
        }
    }
    if(i == a.size() && j < b.size()) {
        for(int k = j; k < b.size(); k++) {
            if(up + (b[k] - '0') >= 10) {
                answer += to_string((up + (b[k] - '0')) % 10);
                up = 1;
            } 
            else {
                answer += to_string((up + (b[k] - '0')));
                up = 0;
            }
        }
    }
    else if(i < a.size() && j == b.size()) {
        for(int k = j; k < a.size(); k++) {
            if(up + (a[k] - '0') >= 10) {
                answer += to_string((up + (a[k] - '0')) % 10);
                up = 1;
            } 
            else {
                answer += to_string((up + (a[k] - '0')));
                up = 0;
            }
        }
    }
    if(up) answer += '1';       
    reverse(answer.begin(), answer.end());
    return answer;
}