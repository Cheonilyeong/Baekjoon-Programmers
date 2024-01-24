#include <string>
#include <vector>

using namespace std;

int check[100004];

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    for(int i : arr) {
        if(check[i] == 0) {
            answer.push_back(i);
            check[i]++;
        }
        if(answer.size() == k) return answer;
    }
    while(answer.size() < k) answer.push_back(-1);
    return answer;
}