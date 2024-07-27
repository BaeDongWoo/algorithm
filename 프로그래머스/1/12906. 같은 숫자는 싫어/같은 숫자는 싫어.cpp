#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> st;
    int lastNum = -1;
    for (int i = 0;i<arr.size();i++){
        if(arr[i]!=lastNum) {
            lastNum = arr[i];
            answer.push_back(lastNum);
            
        }
    }
    

    return answer;
}