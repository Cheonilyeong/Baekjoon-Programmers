#include <bits/stdc++.h>
using namespace std;

int N, num;
string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    stack<int> st;
    while(N--) {
        cin >> s;
        
        if(s == "push") {
            cin >> num;
            st.push(num);
        }
        if(s == "pop") {
            if(st.empty()) cout << -1 << '\n';
            else {cout << st.top() << '\n'; st.pop();}
        }
        if(s == "top") {
            if(st.empty()) cout << -1 << '\n';
            else {cout << st.top() << '\n';}
        }
        if(s == "size") {
            cout << st.size() << '\n';
        }
        if(s == "empty") {
            cout << st.empty() << '\n';
        }   
    }
}