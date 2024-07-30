#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int,int>> setTruck;
    for(int i = 0;i<truck_weights.size();i++){
        setTruck.push(make_pair(truck_weights[i],0));
    };
    int roadWeight = 0;
    vector<pair<int,int>> roadTrucks;
    while(!setTruck.empty()){
        pair<int,int> truck = setTruck.front();
        if(roadWeight+truck.first <= weight && roadTrucks.size() < bridge_length){
            roadWeight+=truck.first;
            roadTrucks.push_back(truck);
            setTruck.pop();
        }
        for(int i = 0;i<roadTrucks.size();i++){
            roadTrucks[i].second+=1;
            // cout << roadTrucks[i].first << " "<< roadTrucks[i].second << " ";
        }
        // cout << "\n" ;
        if(roadTrucks[0].second == bridge_length) {
            roadWeight-=roadTrucks[0].first;
            roadTrucks.erase(roadTrucks.begin());
        }
        answer++;
    }
    while(roadTrucks.size()!=0){
        for(int i = 0;i<roadTrucks.size();i++){
            roadTrucks[i].second+=1;
            // cout << roadTrucks[i].first << " "<< roadTrucks[i].second << " ";
        }
        // cout << "\n" ;
        if(roadTrucks[0].second == bridge_length) {
            roadWeight-=roadTrucks[0].first;
            roadTrucks.erase(roadTrucks.begin());
        }
        answer++;
    }
    return answer+1;
}
// 조건 길 위에 있는 트럭의 무게가 weight를 넘지 않아야 하고 현재 건너는 트럭의 수가 bridge_length보다 작아야함