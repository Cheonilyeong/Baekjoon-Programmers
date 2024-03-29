#include <bits/stdc++.h>
using namespace std;

int N, check[1000];
string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    while(cin >> N) {
    
        getline(cin, s);
        getline(cin, s);

        memset(check, 0, sizeof(check));
        int start = 0, end = 1, cnt = 1, checked = 1, mx = INT_MIN;
        check[s[0]] = 1;

        while(start < end) {
            if(end < s.size()) {
                // 처음 나온거면
                if(check[s[end]] == 0) {
                    // N개 아래면
                    if(checked+1 <= N) {
                        check[s[end]]++;
                        end++, cnt++, checked++;
                    }
                    // N개 넘으면
                    else {
                        while(checked+1 > N) {
                            char startC = s[start];
                            while(s[start] == startC) {
                                check[startC]--;
                                if(check[startC] == 0) checked--;
                                start++;
                                cnt--;
                            }
                        }
                        check[s[end]]++;
                        end++;
                        cnt++;
                        checked++;
                    }
                }
                // 이전에 나왔던거면
                else {
                    check[s[end]]++;
                    end++;
                    cnt++;
                }
            }
            else break;
            mx = max(mx,cnt);
            //cout << s.substr(start, end-start) << ' ' << checked << ' '<<  cnt << '\n';
        }

        if(mx != INT_MIN) cout << mx << '\n';
    }
}