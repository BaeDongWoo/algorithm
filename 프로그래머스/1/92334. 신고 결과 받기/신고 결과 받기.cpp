#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string,int> id_index;
    for(int i =0;i<id_list.size();i++){
        answer.push_back(0);
        id_index[id_list[i]]=i;
    }
    map<string,set<string>> report_list;
    for(int i = 0;i<report.size();i++){
        stringstream ss(report[i]);
        string first,second;
        ss>>first>>second;
        report_list[second].insert(first);
    }
    
    for(auto it : report_list ){
        if(it.second.size()>=k){
            for(auto name : it.second){
                answer[id_index[name]]++;
            }
        }
    }
    
    return answer;
}
/*
1. 신고를 당한 사람이 key 신고를 한사람이 value 
2. 신고를 한 사람이 k이상 이면 신고를 당한사람 목록에 있는 사람들의 인덱스 값에 1씩 추가
id_index{key : id , value : index}

*/