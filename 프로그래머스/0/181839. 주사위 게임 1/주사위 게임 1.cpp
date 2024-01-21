#include <bits/stdc++.h>

using namespace std;

int solution(int a, int b) {
    if((a & 1) && (b & 1)) return pow(a,2) + pow(b,2);
    else if((a & 1) && !(b & 1)) return 2 * (a + b);
    else if(!(a & 1) && (b & 1)) return 2 * (a + b);
    else return abs(a -b);
}