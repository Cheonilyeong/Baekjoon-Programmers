#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer;
    for(int idx = n; idx < num_list.size(); idx++) 
        answer.push_back(num_list[idx]);
    for(int idx = 0; idx < n; idx++) 
        answer.push_back(num_list[idx]);
    return answer;
}