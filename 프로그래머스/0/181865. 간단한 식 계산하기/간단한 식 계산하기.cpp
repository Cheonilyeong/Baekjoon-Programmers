#include <bits/stdc++.h>

using namespace std;

int solution(string binomial) {
    for(int i = 0; i < binomial.size(); i++) {
        if(binomial[i] == '+')
            return atoi(binomial.substr(0, i-1).c_str()) + atoi(binomial.substr(i+2).c_str());
        else if(binomial[i] == '-')
            return atoi(binomial.substr(0, i-1).c_str()) - atoi(binomial.substr(i+2).c_str());
        else if(binomial[i] == '*')
            return atoi(binomial.substr(0, i-1).c_str()) * atoi(binomial.substr(i+2).c_str());
    }
}