#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    for(int i : arr) {
        for(int j = 0; j < i; j++) answer.push_back(i);
    }
    return answer;
}