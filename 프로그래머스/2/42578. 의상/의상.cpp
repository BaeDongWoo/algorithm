#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;
set<string> s;
map<string,vector<string>> m; 
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for(vector<string> ss : clothes){
        s.insert(ss[1]);
        m[ss[1]].push_back(ss[0]);
    }
    for(pair<string, vector<string>> mm: m){
        answer*= mm.second.size()+1;
    }
    return answer-1;
}