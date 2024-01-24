#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for(vector<int> v : queries) {
        int mn = INT_MAX;
        for(int i = v[0]; i < v[1] + 1; i++) {
            if(arr[i] > v[2]) mn = min(mn, arr[i]);
        }
        if(mn == INT_MAX) answer.push_back(-1);
        else answer.push_back(mn);        
    }
    return answer;
}