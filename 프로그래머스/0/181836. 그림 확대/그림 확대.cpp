#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    for(string s : picture) {
        string t = "";
        for(char c : s) {
            for(int i = 0; i < k; i++) {
                t += c;
            }
        }
        for(int i = 0; i < k; i++) {
            answer.push_back(t);
        }
    }
    return answer;
}