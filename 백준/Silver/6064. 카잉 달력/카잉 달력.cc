#include <bits/stdc++.h>
using namespace std;

int T, M, N, x, y;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
int lcm(int a, int b) {
    return (a*b) / gcd(a,b);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> M >> N >> x >> y;
        
        int ret = -1;
        int maxi = lcm(M, N); // 멸망해
        
        for (int i = x; i <= maxi; i+=M){
            int ny = i % N; // y값
            if(ny == 0) // 이때는 y가 최대값이 됨
                ny = N;
            
            if(ny == y){ // 정답
                ret = i;
                break;
            }
        }
        cout << ret << '\n';
    }

    return 0;
}