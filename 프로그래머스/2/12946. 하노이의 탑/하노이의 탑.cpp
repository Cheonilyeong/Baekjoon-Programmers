#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ret;

void hanoi(int n, int from, int other, int to) {

    if(n == 1) {
        ret.push_back(vector<int>{from, to});
    }
    else {
        hanoi(n-1, from, to, other);          // n-1개를 from에 other로
        ret.push_back(vector<int>{from, to}); // 제일 큰 원판을 from에서 to로 
        hanoi(n-1, other, from, to);          // other에 있는 n-1개 to로
    }
    
    
}
vector<vector<int>> solution(int n) {
    hanoi(n, 1, 2, 3);  // 원판의 개수, 1번에서 2번을 거쳐 3번으로
    return ret;
}