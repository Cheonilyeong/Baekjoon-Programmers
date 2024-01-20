#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> num_list) {
    if(num_list.size() >= 11) {
        int answer = 0;
        for(int i : num_list) answer += i;
        return answer;
    }
    else {
        int answer = 1;
        for(int i : num_list) answer *= i;
        return answer;
    }
}