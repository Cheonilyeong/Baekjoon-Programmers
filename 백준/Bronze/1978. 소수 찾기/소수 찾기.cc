#include <bits/stdc++.h>
using namespace std;

int N, num, cnt;

bool check(int num) {
    if(num == 1) return false;
    if(num == 2 || num == 3) return true;
    if(num % 2 == 0) return false;

    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    while(N--) {
        cin >> num;
        if(check(num)) cnt++;
    }   

    cout << cnt;
}