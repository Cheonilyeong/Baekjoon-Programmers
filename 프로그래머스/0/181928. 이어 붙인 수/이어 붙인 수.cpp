#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> num_list) {
    string a, b;
    for(int i : num_list) {
        if(i & 1) a += to_string(i);
        else b += to_string(i);
    }
    return stoi(a) + stoi(b);
}