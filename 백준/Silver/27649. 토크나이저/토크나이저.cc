#include <bits/stdc++.h>
using namespace std;

string s, t, ret;
char pre;
vector<string> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    getline(cin, s);

    for(int idx = 0; idx < s.size(); idx++) {
        char c = s[idx];
        // 구분자면 앞 뒤에 공백 추가
        if(c=='<'||c=='>'||c=='('||c==')'||c==' ') {
            if(t.size())v.push_back(t); t="";
            if(c!=' ')v.push_back(string(1,c));
        }
        // 구분자(& or |)면 앞 뒤에 공백 추가하고 &는 2번
        else if(c=='&'||c=='|') {
            if(pre == c) {pre = '\0'; continue;}
            if(t.size())v.push_back(t); t="";
            v.push_back(string(1,c)+c);
        }
        // 나머지(ex.alpha)
        else t += c;

        pre = c;
    }
    if(t.size())v.push_back(t);

    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
        if(i != v.size()-1) cout << ' ';
    }
}