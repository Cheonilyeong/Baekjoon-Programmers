#include <bits/stdc++.h>

using namespace std;

vector<int> answer;

void go(string num, int l, int r) {
    int here = atoi(num.c_str());
    if(here >= l && here <= r) {
        answer.push_back(here);
    }
    else if(here > r) return;
    go(num + "0", l, r);
    go(num + "5", l, r);
}
    
vector<int> solution(int l, int r) {    
    string num = "5";
    go(num, l, r);
    
    if(answer.empty()) {
        answer.push_back(-1);
    }
    sort(answer.begin(), answer.end());
    return answer;
}