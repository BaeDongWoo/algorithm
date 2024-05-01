#include <string>
#include <vector>

using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int size = board.size();
    string targetColor = board[h][w];
    for(int i = 0;i<4;i++){
        int nx = h+dx[i];
        int ny = w+dy[i];
        if(nx>=0 && nx <size &&ny >= 0 &&ny<size){
            if(targetColor == board[nx][ny]) answer++;
        }
    }
    return answer;
}