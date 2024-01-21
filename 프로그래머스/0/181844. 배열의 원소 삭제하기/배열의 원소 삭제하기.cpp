#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    for(int i : delete_list)
        arr.erase(remove(arr.begin(), arr.end(), i), arr.end());
    return arr;
}