#include <bits/stdc++.h>

using namespace std;

int cnt;
string s;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    getline(cin, s);
    for(int i = 1; i < s.size()-1; i++) {
        if(s[i] == ' ') cnt++;
    }
    if(s == " ") cout << 0;
    else if(cnt == 0) cout << 1;    // ex) "A"
    else cout << cnt+1;
}