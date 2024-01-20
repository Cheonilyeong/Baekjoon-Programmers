#include <bits/stdc++.h>

using namespace std;

string s, p, t;
int pos, ret;

int main(void) {
    cin >> s >> p;
    for(int i = 0; i<p.size(); i++) {
        t += p[i];
        if((pos = s.find(t)) == string::npos) {t = ""; i--; ret++;}
    }
    cout << ret + 1;
}