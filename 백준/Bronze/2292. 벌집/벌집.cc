#include <bits/stdc++.h>
using namespace std;

int N, cnt=1, ret;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; ; i++) { 
        cnt += 6*i;
        if(N <= cnt) {
            ret = i+1;
            break;
        }
    }
    
    cout << ret;
}