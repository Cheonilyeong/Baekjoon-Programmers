#include <bits/stdc++.h>
using namespace std;

int N, check[500005];
vector<int> v;

void era(int N) {

    int color = 1;
    check[1] = 1;

    for(int i = 2; i <= N; i++) {
        if(check[i]) continue;
        check[i] = ++color;
        for(int j = 2*i; j <= N; j+=i) {
            check[j] = color;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    era(N);
    
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        cnt = max(cnt, check[i]);
    }
    
    cout << cnt << '\n';
    for(int i = 1; i <= N; i++) {
        cout << check[i] << ' ';
    }
}