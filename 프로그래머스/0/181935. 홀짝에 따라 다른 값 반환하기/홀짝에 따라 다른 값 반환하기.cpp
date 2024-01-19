#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int result = 0;
    if(n & 1) for(int i = 1; i<=n; i+=2) result += i;
    else for(int i = 2; i<=n; i+=2) result += pow(i,2);
    return result;
}