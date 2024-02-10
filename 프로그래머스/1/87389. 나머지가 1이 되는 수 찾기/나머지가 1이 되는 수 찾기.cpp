#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int i;
    
    for(i = 2; i < n; i++) {
        if(n % i == 1) break;
    }
    
    return i;
}