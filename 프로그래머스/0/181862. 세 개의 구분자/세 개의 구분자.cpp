#include <bits/stdc++.h>

using namespace std;

vector<string> solution(string myStr) {
    int idx;
    string token = "";
    vector<string> ret;
    
    while(1) 
    {
        if(idx == myStr.size()) break;
        
        if(myStr[idx] == 'a' || myStr[idx] == 'b' || myStr[idx] == 'c') 
        {
            if(token.size()) 
            {
                ret.push_back(token);
                token = "";
            }
            idx++;
        }
        else 
        {
            token += myStr[idx];
            idx++;
        }
    }
    if(token.size())
    {
        ret.push_back(token);
    }
    if(ret.size() == 0)
    {
        ret.push_back("EMPTY");
    }
    return ret;
}