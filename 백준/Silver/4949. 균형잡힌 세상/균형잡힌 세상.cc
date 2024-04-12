#include <bits/stdc++.h>
using namespace std;

string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(getline(cin,s)) {
        if(s == ".") break;

        stack<char> st;
        for(char c : s) {
            if(c!='(' && c!=')' && c!='[' && c!=']') continue;
            
            if(st.empty()) {
                st.push(c);
            }
            else if(st.top()=='(' && c==')') st.pop();
            else if(st.top()=='[' && c==']') st.pop();
            else st.push(c);
        }

        if(st.size()) cout << "no\n";
        else cout << "yes\n";
    }
}