#include <bits/stdc++.h>

using namespace std;

int alpha[26], mx, cnt;
string s;

int main(void) {
    cin >> s;
    
    for(char c : s) 
    {
        c = tolower(c);
        mx = max(mx, ++alpha[c - 'a']);
    }
    
    for(int i : alpha) 
    {
        if(i == mx) cnt++;
    }
    
    if(cnt > 1) cout << "?";
    else 
    {
        for(int i = 0; i < 26; i++) 
        {
            if(alpha[i] == mx) cout << char('A' + i);
        }
    }
}