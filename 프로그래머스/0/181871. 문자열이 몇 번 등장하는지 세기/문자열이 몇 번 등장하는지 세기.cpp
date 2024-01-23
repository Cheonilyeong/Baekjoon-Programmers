#include <bits/stdc++.h>

using namespace std;

int solution(string myString, string pat) {
    int cnt = 0;
    
    for(int i = 0; i < myString.size() - pat.size() + 1; i++) 
    {    
        if(myString.substr(i, pat.size()) == pat) 
        {
            cnt++;
        }
    }
    
    return cnt;
}