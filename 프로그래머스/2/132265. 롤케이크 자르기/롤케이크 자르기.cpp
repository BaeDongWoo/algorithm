#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int,int> m;
    map<int,int>mm;
    set<int> s; // 종류
    for(int i=0;i<topping.size() ;i++){
        m[topping[i]]++;
        s.insert(topping[i]);
    }
    for(int i=0;i<topping.size() ;i++){
        m[topping[i]]--;
        mm[topping[i]]++;
        int mCnt = 0;
       if(m[topping[i]]==0) m.erase(topping[i]);
        if(m.size()==mm.size()) answer++;
    }
    return answer;
}