#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> arr, int idx) {
    for(int i = idx; i < arr.size(); i++) 
        if(arr[i]) return i;
    return -1;
}