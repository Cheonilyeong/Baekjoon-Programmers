#include <bits/stdc++.h>

using namespace std;

int n, m;
long long combi[50][50];

long long combination(int n, int r) {
    if(r == 0 || n == r) return 1;
    if(combi[n][r] != -1) return combi[n][r];
    return combi[n][r] = combination(n-1, r-1) + combination(n-1, r);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cin >> m;

    memset(combi, -1, sizeof(combi));
    
    cout << combination(m-1, m-n);        
    // 서로 다른 N개에 M-N개를 넣는다 => n H m-n
    // n H m-n  == (n + m-n - 1) C m-n
    // 중복조합
}