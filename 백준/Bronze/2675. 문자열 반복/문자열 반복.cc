#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    while(t--) {
        cin >> n >> s;
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < n; j++) {
                cout << s[i];
            }
        }
        cout << '\n';
    }
}