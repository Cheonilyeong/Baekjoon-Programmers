#include <bits/stdc++.h>
using namespace std;

string s, ret;
char pre;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    getline(cin, s);

    for(char c : s) {
        // 구분자면 앞 뒤에 공백 추가
        if(c=='<'||c=='>'||c=='('||c==')') {
            if(ret.size() && ret.back()==' ') ret+=c, ret+=' ';
            else if(ret.size() && ret.back()!=' ') ret+=' ', ret+=c, ret+=' ';
            else if(ret.empty()) ret+=c, ret+=' '; 
        }
        // 구분자(& or |)면 앞 뒤에 공백 추가하고 &는 2번
        else if(c=='&'||c=='|') {
            if(pre == c) {pre='\0';continue;}
            if(ret.size() && ret.back()==' ') ret+=c, ret+=c, ret+=' ';
            else if(ret.size() && ret.back()!=' ') ret+=' ', ret+=c, ret+=c, ret+=' ';
            else if(ret.empty()) ret+=c, ret+=c, ret+=' '; 
        }
        // 공백이면
        else if(c == ' ') {
            if(ret.size() && ret.back()!=' ') ret+=c;
        }
        // 나머지(ex.alpha)
        else ret+=c;

        pre = c;
    }

    if(ret.back()==' ') ret.erase(ret.size()-1);
    cout << ret;
}