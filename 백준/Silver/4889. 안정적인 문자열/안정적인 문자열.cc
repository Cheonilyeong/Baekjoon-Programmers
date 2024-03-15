#include <bits/stdc++.h>
using namespace std;

int T, cnt;
string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(cin >> s) {

        if(s.front() == '-') break;

        T++;
        cnt = 0;
        stack<char> st;

        for(char c : s) {
            if(st.empty()) st.push(c);
            else if(st.top() == '{' && c == '}') {st.pop();}
            else {st.push(c);}
        }

        while(!st.empty()) {
            char c = st.top();
            st.pop();

            if(st.top() == '{' && c == '{') {cnt++; st.pop();} 
            else if(st.top() == '}' && c == '{') {cnt+=2; st.pop();} 
            else if(st.top() == '}' && c == '}') {cnt++; st.pop();} 
        }

        cout << T << ". " << cnt << '\n';
    }
}