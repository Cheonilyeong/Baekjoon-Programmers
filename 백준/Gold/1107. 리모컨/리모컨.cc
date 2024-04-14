#include <bits/stdc++.h>
using namespace std;

int N, M, num, cnt=INT_MAX, broken[15];
queue<int> q;

bool check(string s) {
    for(char c : s) {
        if(broken[c-'0']) return false;
    }
    return true;
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> num;
        broken[num] = 1;
    }

    // 채널 100에서 이동
    cnt = abs(100-N);

    // 채널 이동 후 + or -
    for(int i = 0; i <= 1111111; i++) {
        string s = to_string(i);

        if(check(s)) {
            cnt = min(cnt, (int)s.size()+abs(N-i));
        }
    }
        
    cout << cnt;
}