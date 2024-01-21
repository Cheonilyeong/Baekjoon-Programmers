#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    for(char& c : myString) {
        char t = c;
        if(t == 'A') c = 'B';
        else if(t == 'B') c = 'A';
    }
    long long pos;
    if((pos = myString.find(pat)) == string::npos) return 0;
    else return 1;
}