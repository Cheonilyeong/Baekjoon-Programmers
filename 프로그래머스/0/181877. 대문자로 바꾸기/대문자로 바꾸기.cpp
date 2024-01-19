#include <bits/stdc++.h>

using namespace std;

string solution(string myString) {
    string answer = "";
    for(char c : myString) {
        if(islower(c)) answer += toupper(c);
        else answer += c;
    }
    return answer;
}