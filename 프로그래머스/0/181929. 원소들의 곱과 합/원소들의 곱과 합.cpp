#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> num_list) {
    int a = 1, b = 0;
    for(int i : num_list) {
        a *= i; 
        b += i;
    }
    return (a < pow(b,2)) ? 1 : 0;
}