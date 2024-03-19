#include <bits/stdc++.h>
using namespace std;

int num, ret;

int main(void) {

    for(int i = 0; i < 5; i++) {
        cin >> num;
        ret += pow(num,2);
    }

    cout << ret % 10;
}