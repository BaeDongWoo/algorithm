#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
void checkNetwork(int start, vector<vector<int>>& v, vector<int>& visit);
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> visit(n, 0);
    vector<vector<int>> v;
    for(int i =0;i < computers.size();i++){
        vector<int> vv;
        for(int j=0;j<computers[i].size();j++){
            if(computers[i][j] == 1 ) vv.push_back(j);
        }
        v.push_back(vv);
    }
    for (int i = 0; i < n; i++) {
        if (visit[i] == 0) {
            answer++;
            checkNetwork(i, v, visit);
        }
    }
    return answer;
}

void checkNetwork(int start, vector<vector<int>>& v, vector<int>& visit){
    if(visit[start]==1) return;
    visit[start]=1;
    for(int i = 0;i< v[start].size();i++){
        if(visit[v[start][i]]==0){
            checkNetwork(v[start][i],v,visit);
        }
    }
}