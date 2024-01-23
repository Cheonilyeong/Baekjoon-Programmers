#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    // 2의 거듭제곱은 2, 4, 8, 16... 으로
    // 2(1), 4(10), 8(100), 16(1000)... 모두 1이 하나인 특징
    // n & (n - 1) == 0 && n != 0
    
    while(arr.size() & (arr.size() - 1)) {
        arr.push_back(0);
    }
    return arr;
    
}