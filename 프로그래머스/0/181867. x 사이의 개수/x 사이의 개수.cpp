#include <bits/stdc++.h>

using namespace std;
int cnt;

vector<int> solution(string myString) {
    vector<int> answer;
    for(char c : myString) {
        if(c == 'x') {
            answer.push_back(cnt);
            cnt = 0;
        }
        else cnt++;
    }
    answer.push_back(cnt);
    return answer;
}