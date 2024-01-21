#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> num_list) {
    int oddSum = 0, evenSum = 0;
    for(int i = 0; i < num_list.size(); i++) {
        if((i + 1) & 1) oddSum += num_list[i];
        else evenSum += num_list[i];
    }
    return (oddSum >= evenSum) ? oddSum : evenSum;
}