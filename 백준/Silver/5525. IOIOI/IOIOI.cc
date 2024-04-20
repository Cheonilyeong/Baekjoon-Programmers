#include <bits/stdc++.h>
using namespace std;

int N, M, k, cnt;
string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    cin >> M;
    cin >> s;
    
    
    for(int i = 0; i < M; i++) {
        if(s[i] == 'O') continue;

        while(s[i+1] == 'O' && s[i+2] == 'I') {
            k++;
            if(k == N) {
                k--;
                cnt++;
            }
            i+=2;
        }
        k = 0;
    }

    cout << cnt;
}