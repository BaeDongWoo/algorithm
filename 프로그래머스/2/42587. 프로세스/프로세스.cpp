#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> setPriorities;
    for(int i =0;i<priorities.size();i++){
        setPriorities.push(make_pair(priorities[i],i));
    }
    while(1){
        pair<int,int> p = setPriorities.front(); // 맨앞에 값 가져오기
        bool flag = true;
        
        queue<pair<int,int>> tempPriorities=setPriorities; // 큐를 복사
        
        while(!tempPriorities.empty()){// 복사한 큐를 돌면서 더 큰 값이 있나 찾기
            pair<int,int> pp = tempPriorities.front();
            
            if(p.first < pp.first) {
                setPriorities.push(p);
                flag = false;
                break;
            }
            else {
                tempPriorities.pop();
            }
        }
        setPriorities.pop();
        if(flag) {
            answer++; //값을 찾았으므로 answer
             if(p.second == location) break;
        }
        
        
       
    }
    return answer;
}
// 한개씩 가져와서 