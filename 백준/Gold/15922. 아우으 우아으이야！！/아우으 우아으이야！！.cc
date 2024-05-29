// 15922 아우으 우아으이야!!
#include <bits/stdc++.h>
using namespace std;

int N, a, b, l, r=-1000000001;
long long ret;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        if(r == -1000000001) {l = a; r = b;}
        else if(a <= r) {r = max(r, b);}
        else if(a > r) {ret += (r-l); l = a; r = b;}
    }
    ret += (r-l);

    cout << ret;
}