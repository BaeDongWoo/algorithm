#include<string>
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;

bool solution(string s)
{
    bool answer = true;
    for(int i = 0;i<s.size();i++){
        if(s[i]=='(') q.push(s[i]);
        else {
            if(q.empty()) return false;
            if(q.front()=='(') q.pop();
        }
    }
    if(!q.empty()) return false;
    return answer;
}