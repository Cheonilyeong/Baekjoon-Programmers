#include <bits/stdc++.h>

using namespace std;
int pos; 

int solution(string myString, string pat) {
    for(char& c : myString) c = tolower(c);
    for(char& c : pat) c = tolower(c);
    if((pos = myString.find(pat)) == string::npos) return 0;
    return 1;
}