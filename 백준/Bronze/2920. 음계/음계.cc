#include <bits/stdc++.h>
using namespace std;

string s;
char c;

int main(void) {

    for(int i = 0; i < 8; i++) {
        cin >> c;
        s += c;
    }

    if(s == "12345678") cout << "ascending";
    else if(s == "87654321") cout << "descending";
    else cout << "mixed";
}