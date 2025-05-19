#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
bool comp(int a,int b);
int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    sort(wallet.begin(),wallet.end(),comp);
    while(1){
        sort(bill.begin(),bill.end(),comp);
       if(wallet[0]>=bill[0] && wallet[1]>=bill[1]) break;
        bill[0]=floor(bill[0]/2);
        answer++;
    }
    
    return answer;
}
bool comp (int a , int b) {
    return a>b;
}
// 지갑의 큰쪽이 지폐의 큰쪽보다 크고, 지갑의 작은쪽도 지폐의 작은쪽보다 커질때까지 접기