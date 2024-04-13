#include <bits/stdc++.h>
using namespace std;

long long N, ret;
const int INF=1234567891;
string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> s;

    int cnt = 0;
    for(char c : s) {
        long long sum = c-'a'+1;
        for(int i = 0; i < cnt; i++) {
            sum *= 31;
            sum %= INF;
        }
        cnt++;
        ret += sum;
        ret %= INF;
    }

    cout << ret;
}