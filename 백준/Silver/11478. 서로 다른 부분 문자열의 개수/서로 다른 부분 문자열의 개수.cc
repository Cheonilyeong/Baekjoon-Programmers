#include <bits/stdc++.h>
using namespace std;

string s;
set<string> st;

int main(void) {

    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        for(int j = i; j < s.size(); j++) {
            st.insert(s.substr(i, j-i+1));
        }
    }

    cout << st.size();
}