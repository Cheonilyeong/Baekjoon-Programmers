#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct CompareSecond{
    bool operator()(const pair<int , int >&a , pair<int , int>&b)const{
        if(a.second == b.second) return a.first < b.first;
        else return a.second < b.second;
    }
};

int main(){
    int N;
    cin >> N;
    vector<pair<int , int> > meet(N);
    int result = 1;
    int endtime ;

    for(int i = 0 ; i < N; i++){

        cin >> meet[i].first >> meet[i].second;
    }
    sort(meet.begin(),meet.end(),CompareSecond());

    endtime = meet[0].second;

    for(int i = 1; i < N; i++){
        if(meet[i].first < endtime) {continue;}
        else{
            endtime = meet[i].second;
            result++;
        }
    }

    cout << result;

    return 0;
}