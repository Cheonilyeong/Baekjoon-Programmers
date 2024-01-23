#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for(vector<int> v : queries) {
        swap(arr[v[0]], arr[v[1]]);
    }
    return arr;
}