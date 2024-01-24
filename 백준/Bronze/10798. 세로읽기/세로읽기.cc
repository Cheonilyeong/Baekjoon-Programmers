#include <bits/stdc++.h>
using namespace std;

int mx;
char m[5][15];
string s;

int main(void) {

    for(int i = 0; i < 5; i++) {
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            m[i][j] = s[j];
        }
        mx = max(mx, (int)s.size());
    }
    
    for(int j = 0; j < mx; j++) {
        for(int i = 0; i < 5; i++) {
            if(m[i][j] != '\0') cout << m[i][j];
        }
    }
}