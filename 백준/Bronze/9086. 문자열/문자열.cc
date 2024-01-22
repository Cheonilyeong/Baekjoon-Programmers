#include <bits/stdc++.h>

using namespace std;

int t;
string s;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    while(t--) {
        cin >> s;
        cout << s[0] << s[s.size()-1] << '\n';
    }
}