#include <bits/stdc++.h>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    
    vector<char> f = {'A','C','F','J','M','N','R','T'};
    
    do{
        bool flag = true;
        map<char,int> mp;
        
        for(int i = 0; i < f.size(); i++) {
            mp[f[i]] = i;
        }
        
        for(string s : data) {
            char f1 = s[0];
            char f2 = s[2];
            char op = s[3];
            int num = s[4] - '0';
            
            if(op == '=') {
                if(abs(mp[f1] - mp[f2]) == num + 1) continue;
                else {flag = false; break;}
            }
            else if(op == '<') {
                if(abs(mp[f1] - mp[f2]) < num + 1) continue;
                else {flag = false; break;}
            }
            else if(op == '>') {
                if(abs(mp[f1] - mp[f2]) > num + 1) continue;
                else {flag = false; break;}
            }
        }
        
        if(flag) answer++;
        
    }while(next_permutation(f.begin(), f.end()));
    
    return answer;
}