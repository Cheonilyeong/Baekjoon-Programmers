#include <bits/stdc++.h>
using namespace std;

int M, num, S[30];
string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> M;

    while(M--) {
        cin >> s;

        if(s == "add") {
            cin >> num;
            S[num] = 1;
        }
        if(s == "remove") {
            cin >> num;
            S[num] = 0;
        }
        if(s == "check") {
            cin >> num;
            cout << S[num] << '\n';
        }
        if(s == "toggle") {
            cin >> num;
            if(S[num]) S[num] = 0;
            else S[num] = 1;
        }
        if(s == "all") {
            for(int i = 1; i <= 20; i++) S[i] = 1;
        }
        if(s == "empty") {
            for(int i = 1; i <= 20; i++) S[i] = 0;
        }
    }
}