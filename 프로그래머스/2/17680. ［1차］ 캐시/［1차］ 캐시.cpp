#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iostream>
using namespace std;
vector<string> v;
const int CACHE_HIT = 1;
const int CACHE_MISS = 5;
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize == 0){
        answer = cities.size()*5;
        return answer;
    }
    for(int i = 0;i<cities.size();i++){
        string city = cities[i];
        transform(city.begin(),city.end(),city.begin(),::toupper);
        if(v.size()<cacheSize){
            auto iter = find(v.begin(), v.end(), city);
            if(iter==v.end()){
                v.push_back(city);
                answer+=5;
            }
            else if(iter!=v.end()){
                int index = iter -v.begin();
                v.erase(v.begin()+index);
                v.push_back(city);
                answer+=1;
            }
            
        }
        else if(v.size()==cacheSize){
            auto iter = find(v.begin(), v.end(), city);
            if(iter!=v.end()){
                int index = iter -v.begin();
                v.erase(v.begin()+index);
                v.push_back(city);
                answer+=1;
            }
            else if(iter==v.end()){
                v.erase(v.begin());
                v.push_back(city);
                answer+=5;
            }
        }
    }
   
    return answer;
}
    /*
    1. v의 사이즈가 캐시사이즈 보다 작으면 캐시에 저장 하고 +5
    2. v의 사이즈가 캐시사이즈 보다 크면 캐시 조회
        2.1 v에 해당 도시가 있으면 +1
            2.1.1 해당 도시를 삭제하고 다시 저장
        2.2 v에 해당 도시가 없으면 +5
            2.2.1 캐시의 제일 마지막 도시를 삭제하고 새로운 도시를 입력
    */