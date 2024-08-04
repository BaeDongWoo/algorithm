#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> m;
    // sort(participant.begin(),participant.end());
    // sort(completion.begin(),completion.end());
    // answer = participant[participant.size()-1];
    for(int i =0;i<completion.size();i++){
        m[completion[i]]++;
    }
    for(int i =0;i<participant.size();i++){
        if(m[participant[i]] == 0){ 
            return participant[i];
        }
        else m[participant[i]]--;
    }
    return answer;
}