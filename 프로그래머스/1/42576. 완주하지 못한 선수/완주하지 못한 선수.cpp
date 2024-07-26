#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    answer = participant[participant.size()-1];
    for(int i =0;i<completion.size();i++){
        if(participant[i]!=completion[i]) return participant[i];
    }
    return answer;
}