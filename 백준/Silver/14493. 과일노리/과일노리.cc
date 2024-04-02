#include <bits/stdc++.h>
using namespace std;

int N, a, b, t;

int main(void) {

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        if(t % (a+b) < b) {
            t += (b - t % (a+b));
            t++;
        }
        else {
            t++;
        }
    }

    cout << t;
}