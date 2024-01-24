#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    // 행의 수(열의 길이) > 열의 수 (모든 행의 길이는 같다)
    if(arr.size() > arr[0].size()) {
        int di = arr.size() - arr[0].size();
        for(vector<int>& v : arr) {
            for(int i = 0; i < di; i++) {
                v.push_back(0);
            }
        }
    }
    else if(arr.size() < arr[0].size()) {
        int di = arr[0].size() - arr.size();
        for(int i = 0; i < di; i++) {
            arr.push_back(vector<int>(arr[0].size()));
        }
    }
    return arr;
}