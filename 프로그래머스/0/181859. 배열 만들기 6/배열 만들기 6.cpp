#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    int i = 0;
    while(i < arr.size()) {
        if(stk.empty()) {
            stk.push_back(arr[i++]);
        }
        else if(stk.back() == arr[i]) {
            stk.pop_back();
            i++;
        }
        else if(stk.back() != arr[i]) {
            stk.push_back(arr[i++]);
        }
    }
    if(stk.empty()) return vector<int>{-1};
    return stk;
}