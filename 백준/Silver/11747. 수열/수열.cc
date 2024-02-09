#include <bits/stdc++.h>
using namespace std;

int N, a;
string s;
map<string,int> mp;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> a;
        s += to_string(a);
    }

    // 브루트포스
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            string t = s.substr(i, j-i+1);
            mp[t] = 1;
        }
    }

    // 나오지 않은 가장 작은 음이 아닌 정수 찾기
    for(int i = 0; ; i++) {
        if(mp[to_string(i)] == 0) {
            cout << i << '\n';
            break;
        }
    }
}