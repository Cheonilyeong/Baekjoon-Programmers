#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int dogX, dogY;
    int maxX = park[0].size();
    int maxY = park.size();
    char copy_map[51][51];
    
    for(int i = 0; i < maxY; i++) {
        for(int j = 0; j < maxX; j++) {
            copy_map[i][j] = park[i][j];
            if(copy_map[i][j] == 'S') tie(dogY,dogX) = {i,j};
        }
    }
    
    for(string s : routes) {
        bool flag = true;
        int nextX = dogX;
        int nextY = dogY;
        for(int i = 0; i < (s[2]-'0'); i++) {
            if(s[0] == 'N') nextY--;
            if(s[0] == 'S') nextY++;
            if(s[0] == 'W') nextX--;
            if(s[0] == 'E') nextX++;
            
            if(nextX < 0 || nextX >= maxX || nextY < 0 || nextY >= maxY || copy_map[nextY][nextX] == 'X') {
                flag = false;
                break;
            }            
        }
        if(flag) {
            dogX = nextX;
            dogY = nextY;
        }
        cout << "dogX = " << dogX << " dogY = " << dogY << '\n';
    }
    
    answer.push_back(dogY);
    answer.push_back(dogX);
    
    return answer;
}