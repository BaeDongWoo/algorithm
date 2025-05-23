#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
int findSpace (int x , int y,vector<vector<string>>& park,int size);
int comp (int a, int b);
int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    sort(mats.begin(),mats.end());
    for(int i =0;i<park.size();i++){
        for(int j=0;j<park[0].size();j++){
            if(park[i][j] == "-1") {
               for(int k=0;k<mats.size();k++){
                   int chk = findSpace(i,j,park,mats[k]);
                   if(chk != -1 && chk > answer){
                     answer = chk;
                   }
               }
            }
        }
    }
    
    return answer;
}
int findSpace (int x , int y,vector<vector<string>>& park,int size){
    if(x+size>park.size() || y+size>park[0].size()){
        cout<< x << ' ' << y << ' ' << size << '\n';
        return -1;
    }
    for(int i = x;i<x+size;i++){
        for(int j=y;j<y+size;j++){
            if(park[i][j]!="-1") return -1;
        }
    }
        return size;
}