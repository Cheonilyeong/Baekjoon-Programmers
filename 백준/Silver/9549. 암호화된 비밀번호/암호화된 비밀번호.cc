#include <bits/stdc++.h>
using namespace std;

int T, cnt1[26], cnt2[26];
string s1, s2;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--) {

        cin >> s1;
        cin >> s2;

        for(char c : s2) {cnt2[c-'a']++;}

        deque<char> dq;
        int check;
        for(char c : s1) {
            if(dq.size() < s2.size()) {
                dq.push_back(c);
                cnt1[c-'a']++;
            }
            else if(dq.size() == s2.size()) {
                char pc = dq.front(); dq.pop_front();
                cnt1[pc-'a']--;

                dq.push_back(c);
                cnt1[c-'a']++;
            }

            if(dq.size() == s2.size()) {
                check = 0;
                for(int i = 0; i < 26; i++) {
                    if(cnt1[i] == cnt2[i]) check++;
                }

                if(check == 26) break;
            }
        }

        if(check == 26) cout << "YES\n";
        else cout << "NO\n";

        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
    }

}