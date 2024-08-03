#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer; 
    for(int i = 1;i<=yellow;i++){
        if(yellow%i == 0){
            int w = i; //가로 사이즈
            int h = yellow/i; // 세로 사이즈
            
            int blockW = w+2;
            int blockH = h+2;
            
            int totalBlockSize = blockW * blockH;
            
            if(totalBlockSize-yellow == brown){
                answer.push_back(blockH);
                answer.push_back(blockW);
                break;
            }
        }
    }
    return answer;
}