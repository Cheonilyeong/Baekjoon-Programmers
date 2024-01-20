#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers, int n) {
    int answer = 0;
    for(int i : numbers) {
        if((answer += i) > n) return answer;
    }
    return answer;
}