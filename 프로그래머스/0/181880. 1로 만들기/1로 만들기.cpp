#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    for(int i : num_list) {
        
        while(i != 1) {
            
            if(i & 1) i = (i - 1) / 2;
            else i /= 2;
            answer++;
            
        }
    }
    return answer;
}