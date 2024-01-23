#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    for(string str : intStrs) {
        int a = atoi(str.substr(s, l).c_str());
        if(a > k) answer.push_back(a);
    }
    return answer;
}