#include <bits/stdc++.h>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int cnt = 0;
    int color[n+1];
    
    memset(color, 0, sizeof(color));
    
    for(int i : section) {
        color[i] = 1;
    }
    
    for(int i = 1; i < n+1; i++) {
        if(color[i] == 1) {
            i += m-1;
            cnt++;
        }
    }
    
    return cnt;
}