#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> q;
    int lastNum = -1;
    for (int i = 0;i<arr.size();i++){
        if(q.empty()) q.push(arr[i]);
        else {
            if(q.back() != arr[i]) {
                
                q.push(arr[i]);
                
            }
        }
    }
    while(!q.empty()){
        int n = q.front();
        q.pop();
        answer.push_back(n);
    }
    return answer;
}