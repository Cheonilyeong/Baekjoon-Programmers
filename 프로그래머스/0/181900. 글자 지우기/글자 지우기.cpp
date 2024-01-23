#include <bits/stdc++.h>

using namespace std;

int check[104];

string solution(string my_string, vector<int> indices) {
    string answer = "";
    
    for(int i : indices) {
        check[i] = 1;
    }
    
    for(int i = 0; i < my_string.size(); i++) {
        if(check[i] == 0) answer += my_string[i];
    }
    
    return answer;
}