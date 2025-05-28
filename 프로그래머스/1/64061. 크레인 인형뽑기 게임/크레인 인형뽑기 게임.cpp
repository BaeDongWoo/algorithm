#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<queue<int>> vq;
    for(int i =0;i<board.size();i++){
        queue<int> q;
        for (int j=0;j<board.size();j++){
          if(board[j][i]!=0){
               q.push(board[j][i]);
          }
           
        }
        vq.push_back(q); 
    }
    stack<int> basket;
    for(int i = 0;i<moves.size();i++){
        if(!vq[moves[i]-1].empty()){
            if(!basket.empty()){
                if(vq[moves[i]-1].front()==basket.top()) {
                    basket.pop();
                    answer+=2;
                }
                else{
                    basket.push(vq[moves[i]-1].front());
                } 
            }
            else{
                basket.push(vq[moves[i]-1].front());
            }
            vq[moves[i]-1].pop();
        }
        
    }
    return answer;
}