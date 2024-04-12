#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> s;

        stack<char> st;
        for(char c : s) {
            if(st.empty()) st.push(c);
            else if(st.top()=='(' && c==')') st.pop();
            else st.push(c);
        }

        if(st.size()) cout << "NO\n";
        else cout << "YES\n";
    }
}