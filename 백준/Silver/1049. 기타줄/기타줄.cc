#include <bits/stdc++.h>
using namespace std;

int N, M;
int a, b;
int minA=INT_MAX, minB=INT_MAX;

int main(void) {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        minA = min(minA, a);
        minB = min(minB, b);
    }

    if(N < 6) {
        cout << min(minA,N*minB);
    }
    else {
        if(minA >= minB*6) cout << N*minB;
        if(minA < minB*6) cout << min((N/6)*minA + (N%6)*minB, (N/6+1)*minA);
    }
}