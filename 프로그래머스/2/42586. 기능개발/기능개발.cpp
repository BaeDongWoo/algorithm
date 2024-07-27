#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    for(int i = 0;i<progresses.size();i++){
        int day = ceil((100.0-progresses[i])/speeds[i]);
        days.push_back(day);
    }
    int p = 0;
    int pp = 0;
    int cnt = 0;
    while(p != days.size()){
        if(days[p]>=days[pp]){
            cnt++;
            pp++;
        }
        else{
            answer.push_back(cnt);
            cnt=0;
            p=pp;
        }
        if(pp==days.size()){
            answer.push_back(cnt);
            break;
        };
    }
    return answer;
}