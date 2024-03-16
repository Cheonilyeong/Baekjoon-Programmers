#include <bits/stdc++.h>
using namespace std;

int N, ret;
char c;
string s;
set<string> st;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    while(N--) {
        cin >> s;
        st.insert(s);

        reverse(s.begin(), s.end());
        if(st.find(s) != st.end()) {
            ret = s.size();
            c = s[ret/2];
        }
    }

    cout << ret << ' ' << c;
}