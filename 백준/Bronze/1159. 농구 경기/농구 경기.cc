#include <bits/stdc++.h>
using namespace std;

int N, cnt[30];
string s;
bool flag;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N; 

    while(N--) {
        cin >> s;
        cnt[s[0] - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        if(cnt[i] >= 5) {
            flag = true;
            cout << (char)('a' + i);
        }
    }

    if(flag == false) cout << "PREDAJA";
}