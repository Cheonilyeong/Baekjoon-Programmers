#include <bits/stdc++.h>
using namespace std;

int N, M, B, num, ret=INT_MAX, hi=INT_MIN;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> B;

    vector<int> v;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> num;
            v.push_back(num);
        }
    }

    for(int i = 0; i <= 256; i++) {
        int p=0, m=0;

        for(int num : v) {
            if(num < i) p+=i-num;
            if(num > i) m+=num-i;
        }

        if(p<=m+B) {
            if(ret >= 2*m+p) {
                ret = 2*m+p;
                hi = i;
            }
        }
    }
    cout << ret << ' ' << hi;
}