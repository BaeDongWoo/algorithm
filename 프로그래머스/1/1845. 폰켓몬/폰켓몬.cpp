#include <vector>
#include <iostream>
#include <set>
using namespace std;
set<int> s;
int solution(vector<int> nums)
{
    int answer =nums.size()/2;
    for(int i = 0;i<nums.size();i++){
            s.insert(nums[i]);
        }
    if(s.size()<answer) answer = s.size();
    return answer;
}