#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int cnt = 0, n = board.size();
    int dh[] = {-1, 0, 1, 0};
    int dw[] = {0, 1, 0, -1};
    
    for(int i = 0; i<4; i++) {
        
        int nh = h + dh[i];
        int nw = w + dw[i];
        
        if(nh < 0 || nh >= n || nw < 0 || nw >= n) continue;
        if(board[nh][nw] == board[h][w]) cnt++;
    }
    return cnt;
}