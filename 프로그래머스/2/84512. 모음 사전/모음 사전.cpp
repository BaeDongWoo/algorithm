#include <string>
#include <vector>
#include <iostream>
using namespace std;
int cnt = 0;
void recusive(int idx,string temp, string w,int &answer);
int solution(string word) {
    string temp = "";
    int answer = 0;
    recusive(0,temp,word,answer);
    return answer;
}

void recusive(int idx,string temp, string w,int &answer){
    string alpaList[5] = {"A", "E", "I", "O", "U"};
    if(temp.size() >= 5){
        return;
    }
    else {
        string newTemp  = temp;
        for(int i = idx;i<5;i++){
            newTemp+=alpaList[i];
            cnt++;
            if(newTemp == w) answer = cnt;
            recusive(0,newTemp,w,answer);
            newTemp.erase(newTemp.length() - 1);
        }
    }
}