#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
/*
1.begin과 words[i]를 비교 한개만 바뀌면 begin을 words[i]로 변경 후 cnt++;
2.바뀐 begin이 target과 같은지 비교 같다면 cnt를 리턴
3.다르다면 words에서 begin을 지운 뒤 q에 푸쉬 

1~3 반복
*/
bool checkWords (string word, string target);
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    if(find(words.begin(),words.end(),target)==words.end()) return 0;
    queue<pair<pair<string,vector<string>>,int>> q;
    q.push({{begin,words},0});
    while(!q.empty()){
        vector<string> wordList= q.front().first.second;
        string word = q.front().first.first;
        int cnt = q.front().second;
        q.pop();
        for(int i = 0;i< wordList.size();i++){
            string newWord;
            vector<string> newList = wordList;
            int c = cnt;
            if(checkWords(word,wordList[i])){
                newWord = wordList[i];
                c++;
                if(newWord == target) return c;
                else {
                    remove(newList.begin(),newList.end(),newWord);
                    q.push({{newWord,newList},c});
                }
            }
        }
    }
    
    return answer;
}

bool checkWords (string word, string target){
    int cnt =0;
    for(int i=0;i<word.length();i++){
        if(word[i]!=target[i]) cnt++;
    }
    if(cnt==1) return true;
    else return false;
}