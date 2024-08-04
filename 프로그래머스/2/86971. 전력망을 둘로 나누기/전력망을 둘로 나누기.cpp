#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
int runTree(int node, map<int,vector<int>> m,int &cnt,vector<bool> &visited);
int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    
    for(int i =0;i<wires.size();i++){
        map<int,vector<int>> m;
        
        for(int j = 0;j<wires.size();j++){
            if(i!=j){
                int s = wires[j][0];
                int e = wires[j][1];
                
                m[s].push_back(e);
                m[e].push_back(s);
                
            }
        }
        int cnt =1;
        vector<bool> visited(n,false); 
        int count = runTree(1,m,cnt,visited);
        int ncoutn = n-count;
        int temp = abs(count-ncoutn);
        answer = min(answer,temp);
    }
    return answer;
}

int runTree(int node, map<int,vector<int>> m,int &cnt,vector<bool> &visited){
    visited[node]=true;
    for(int i=0;i<m[node].size();i++){
        if(!visited[m[node][i]]){
            cnt++;
            runTree(m[node][i],m,cnt,visited);
        }
    }
    return cnt;
}