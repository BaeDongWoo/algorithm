#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const vector<int> &a, const vector<int> &b){
    return a[1] <= b[1];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0, timer = 0, cnt = jobs.size();
    sort(jobs.begin(), jobs.end(), comp); // {요청시간, 업무시간} // 단, 업무시간이 짧은 순으로 배치
    while(!jobs.empty()){
        for(int i=0; i<jobs.size(); i++){
            if(jobs[i][0]<=timer){
                timer += jobs[i][1];
                answer += (timer-jobs[i][0]);
                jobs.erase(jobs.begin()+i);
                break;
            }
            if(i==jobs.size()-1) timer++;
        }
    }
    return answer/cnt;
}
// 각 작업에 대기시간을 구하고 대기시간이 작은 순서대로 진행
// 현재 시간에서 가장 적은 대기시간을 기준으로 작업 진행
// 첫번째 작업 이후 
// 업무시간 
