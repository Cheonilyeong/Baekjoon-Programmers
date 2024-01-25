#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    for(int idx = 0; idx < query.size(); idx++) {
        if(idx & 1) {
            arr.erase(arr.begin(), arr.begin()+query[idx]);
        }
        else {
            arr.erase(arr.begin()+query[idx]+1, arr.end());
        }
    }
    return arr;
}