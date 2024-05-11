#include <bits/stdc++.h>
using namespace std;

int N, num, sum;

int main(void) {
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num;
        sum += abs(num);
    }
    for(int i = 0; i < N; i++) {
        cin >> num;
        sum += abs(num);
    }

    cout << sum;
}