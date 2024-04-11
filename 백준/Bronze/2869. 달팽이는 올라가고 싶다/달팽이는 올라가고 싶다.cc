#include <bits/stdc++.h>
using namespace std;

int A, B, V, day;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> A >> B >> V;

    day += (V-A)/(A-B);
    if((V-A)%(A-B) != 0) day++;

    if(A >= V) cout << "1";
    else cout << day + 1;

    return 0;
}