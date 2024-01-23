#include <bits/stdc++.h>

using namespace std;

int mn = INT_MAX, mx = INT_MIN;

vector<int> solution(vector<int> arr) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == 2) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }
    if(mn == INT_MAX && mx == INT_MIN) return vector<int>{-1};
    else return vector<int>(arr.begin()+mn, arr.begin()+mx+1);
}