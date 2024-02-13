#include <bits/stdc++.h>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    for(int i = 1; i < food.size(); i++) {
        for(int j = 0; j < food[i]/2; j++) {
            answer += i + '0';   
        }
    }
    
    string t = answer;
    answer += '0';
    reverse(t.begin(), t.end());
    answer += t;
    
    return answer;
}