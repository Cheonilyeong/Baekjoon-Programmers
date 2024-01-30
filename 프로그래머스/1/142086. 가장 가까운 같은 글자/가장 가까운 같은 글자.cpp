#include <bits/stdc++.h>

using namespace std;

int alpha[30];

vector<int> solution(string s) {
    memset(alpha, -1, sizeof(alpha));
    vector<int> answer;
    
    for(int i = 0; i<s.size(); i++) {
        if(alpha[s[i]-'a'] == -1) answer.push_back(-1);
        else answer.push_back(i - alpha[s[i]-'a']);
        alpha[s[i]-'a'] = i;
    }
    return answer;
}