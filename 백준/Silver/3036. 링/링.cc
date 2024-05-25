#include <bits/stdc++.h>
using namespace std;

int N, arr[104];

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    // 링의 반지름
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 구하기
    for(int i = 1; i < N; i++) {
        int a = gcd(arr[0], arr[i]);
        cout << arr[0]/a << '/' << arr[i]/a << '\n';
    }
}