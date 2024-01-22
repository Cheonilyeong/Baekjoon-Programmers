#include <bits/stdc++.h>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int cnt = 0, sum = 0;
    for(bool check : included) {
        int now = a + d * cnt++;
        if(check) sum += now;
    }
    return sum;
}