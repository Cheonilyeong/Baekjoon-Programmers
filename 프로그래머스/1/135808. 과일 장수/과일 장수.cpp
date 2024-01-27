#include <bits/stdc++.h>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int ret = 0;
    
    sort(score.begin(), score.end(), greater<int>());
    
    for(int i = m-1; i<score.size(); i+=m) {
        ret += score[i] * m;
    }
    
    return ret;
}