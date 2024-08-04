#include <string>
#include <vector>

using namespace std;
int cnt =0;
void rundungeons(int &hp, vector<bool> &visited,vector<vector<int>> dungeons,int &answer);
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int hp = k;
    vector<bool> visited(dungeons.size(),false);
    
    rundungeons(hp,visited,dungeons,answer);
    return answer;
}
void rundungeons(int &hp, vector<bool> &visited,vector<vector<int>> dungeons,int &answer){
    for(int i = 0;i<dungeons.size();i++){
        if(!visited[i]){
            if(hp>=dungeons[i][0]){
                visited[i] = true;
                hp -= dungeons[i][1];
                cnt++;
                answer = max(cnt,answer);
                rundungeons(hp,visited,dungeons,answer);
                visited[i] = false;
                hp += dungeons[i][1];
                cnt--;
            }  
        }
    }
}