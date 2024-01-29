#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    
    vector<vector<int>> answer;
    
    // 람다함수를 한번 사용해보았다.
    auto sortion = [] (string s) -> int {
        if(s == "code") return 0;
        if(s == "date") return 1;
        if(s == "maximum") return 2;
        if(s == "remain") return 3;
    };
    
    int extInt = sortion(ext);
    int sort_byInt = sortion(sort_by);
    
    for(vector<int> v : data) {
        if(v[extInt] < val_ext) answer.push_back(v);
    }
    
    auto comp = [sort_byInt] (const vector<int>& A, const vector<int>& B) -> bool {
        return A[sort_byInt] < B[sort_byInt];
    };
    
    sort(answer.begin(), answer.end(), comp);
    
    return answer;
}