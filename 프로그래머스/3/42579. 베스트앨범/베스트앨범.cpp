#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}
bool compareList(pair<int, int> a,pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}
map<string,int> m; // 아이템별 총 플레이수
map<string,vector<pair<int,int>>> playList;
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i = 0;i<genres.size();i++){
        m[genres[i]]+=plays[i];
        
        playList[genres[i]].push_back(make_pair(i,plays[i]));
        
    }
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(),v.end(),compare);
    for(auto genre : playList) {
        vector<pair<int, int>> sortedList = genre.second; // 복사 생성
        sort(sortedList.begin(), sortedList.end(), compareList); // 정렬
        playList[genre.first] = sortedList; // 정렬된 리스트를 다시 할당
    }
    
    for(auto g : playList){
        for(auto gg : g.second){
            cout << gg.first << " ";
        }
    }
    for(auto g : v){
        answer.push_back(playList[g.first][0].first);
        if(playList[g.first].size() > 1) answer.push_back(playList[g.first][1].first);
    }
    
    return answer;
}
