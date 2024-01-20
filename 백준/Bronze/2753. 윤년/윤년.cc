#include <bits/stdc++.h>

using namespace std;

int a;

int main(void) {
    cin >> a;
    if((a % 400 == 0) || ((a % 4 == 0) && (a % 100 != 0))) cout << 1;
    else cout << 0;
}