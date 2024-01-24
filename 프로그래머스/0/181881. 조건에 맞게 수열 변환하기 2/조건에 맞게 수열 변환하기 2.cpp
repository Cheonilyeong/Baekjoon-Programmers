#include <bits/stdc++.h>

using namespace std;

int mx = INT_MIN;

int solution(vector<int> arr) {
    for(int& i : arr) {
        int cnt = 0;
        while(1) {
            if((i >= 50) && (i & 1 == 0)) {
                i /= 2;
                cnt++;
            }
            else if((i < 50 ) && (i & 1)) {
                i = i * 2 + 1;
                cnt++;
            }
            else {
                mx = max(mx, cnt);
                break;
            }
        }
    }
    return mx;
}