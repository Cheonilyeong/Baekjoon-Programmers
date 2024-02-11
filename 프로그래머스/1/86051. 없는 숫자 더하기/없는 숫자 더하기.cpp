#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<int> check(10, 0);
    
    for(int i : numbers) {
        check[i] = 1;
    }
    
    for(int i = 0; i < 10; i++) {
        if(check[i] == 0) answer += i;
    }
    
    return answer;
}