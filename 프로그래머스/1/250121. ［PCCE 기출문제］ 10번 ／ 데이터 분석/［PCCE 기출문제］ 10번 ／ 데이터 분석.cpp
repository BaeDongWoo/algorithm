#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
/*
*/
using namespace std;
int num;
bool compare(vector<int>a,vector<int>b){
       return a[num] < b[num];
   }

map<string,int> key;
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    string keylist[4]={"code","date","maximum","remain"};
    for(int i = 0;i<4;i++){
        key.insert({keylist[i],i});
    }
    int a = key[ext];
    for(int i = 0;i<data.size();i++){
        int target = data[i][a];
        if(target<val_ext) answer.push_back(data[i]);
    }
    num  = key[sort_by];
    sort(answer.begin(),answer.end(),compare);
    return answer;
}