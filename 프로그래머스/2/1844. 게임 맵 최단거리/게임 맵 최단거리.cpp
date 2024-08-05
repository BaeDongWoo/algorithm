#include<vector>
#include<queue>
using namespace std;
bool visited[100][100] = {false,};
queue<pair<pair<int,int>,int>> q;
int dx[4] = {0 ,1, 0 ,-1};
int dy[4] = {1 ,0 ,-1, 0};
int BFS (int x,int y, int cnt , int w, int h ,vector<vector<int>> maps);
int solution(vector<vector<int>> maps)
{
    int answer = 987654321;
    int w = maps.size();
    int h = maps[0].size();
    answer = BFS(0,0,1,w,h,maps);
    
    return answer;
}
int BFS (int x,int y, int cnt , int w, int h ,vector<vector<int>> maps){
    visited[x][y] = true;
    q.push({{x,y},cnt});
    while(!q.empty()){
        int X = q.front().first.first;
        int Y = q.front().first.second;
        int CNT = q.front().second;
        q.pop();
        
        if (X == w-1 && Y == h-1) return CNT;
        
        for(int i = 0;i<4;i++){
            int nx = X + dx[i];
            int ny = Y + dy[i];
            if(nx < w && nx >= 0 && ny < h && ny >= 0){
                if(maps[nx][ny] == 1 && !visited[nx][ny]){
                    q.push({{nx,ny},CNT+1});
                    visited[nx][ny]=true;
                }
            }
        }
    }
    return -1;
}
