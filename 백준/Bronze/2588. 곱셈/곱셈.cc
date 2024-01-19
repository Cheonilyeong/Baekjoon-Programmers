#include <bits/stdc++.h>
using namespace std;

int a, b, i, j, k;

int main(void) {
    cin >> a >> b;
    i = a * (b%10);
    j = a * (b%100/10);
    k = a * (b/100);
    cout << i << '\n';
    cout << j << '\n';
    cout << k << '\n';
    cout << i + j*10 + k*100 << '\n';
}
