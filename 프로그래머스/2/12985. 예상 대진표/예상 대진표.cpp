#include <bits/stdc++.h>

using namespace std;

int solution(int n, int a, int b)
{
    int round = 1;
    while(1) {
        if(abs(a - b) == 1 && (a - 1) / 2 == (b - 1) / 2) break;
        a = (a - 1) / 2 + 1;
        b = (b - 1) / 2 + 1;
        round++;
    }
    return round;
}