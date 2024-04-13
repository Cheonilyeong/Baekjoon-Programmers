#include <bits/stdc++.h>
using namespace std;

int N, num, cnt[10004];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> num;
        cnt[num]++;
    }   

    for(int i = 0; i < 10004; i++) {
        if(cnt[i]) {
            for(int j = 0; j < cnt[i]; j++) {
                cout << i << '\n';
            }
        }
    }
}