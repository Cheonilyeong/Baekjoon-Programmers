#include <bits/stdc++.h>
using namespace std;

long long M, cnt, fact, num;

int main(void) {
    
    cin >> M;

    num = 1;
    fact = 0;
    while(cnt < M) {
        fact += 5;
        int i = fact;
        while(!(i%5)) {
            i /= 5;
            cnt++;
        }
    }

    if(cnt != M) cout << -1;
    else cout << fact;
}