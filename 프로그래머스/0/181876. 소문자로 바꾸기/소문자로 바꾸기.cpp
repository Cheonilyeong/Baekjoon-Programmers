#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string ret = "";
    for(char c : myString) 
        if(isupper(c)) ret += tolower(c);
        else ret += c;
    return ret;
}