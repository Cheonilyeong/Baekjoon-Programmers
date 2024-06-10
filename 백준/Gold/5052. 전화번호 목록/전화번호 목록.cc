#include <bits/stdc++.h>
using namespace std;

int T, N;
string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> N;

        vector<string> v;
        set<string> st;
        for(int i = 0; i < N; i++) {
            cin >> s;
            v.push_back(s);
            st.insert(s);
        }

        bool flag = true;
        for(string str : v) {
            for(int i = 1; i < str.size(); i++) {
                string t = str.substr(0,i);
                if(st.find(t) != st.end()) flag = false;
            }
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}