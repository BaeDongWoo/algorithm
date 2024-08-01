#include <string>
#include <vector>

using namespace std;
int one[5] ={1,2,3,4,5};
int two[8] ={2, 1, 2, 3, 2, 4, 2, 5};
int three[10] ={3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int ansOne = 0;
    int ansTwo = 0;
    int ansThree = 0;
    int maxAns = 0;
    for(int i = 0 ;i <answers.size();i++){
        if(answers[i]==one[i%5]) ansOne++;
        if(answers[i]==two[i%8]) ansTwo++;
        if(answers[i]==three[i%10]) ansThree++;
        maxAns=max(ansOne,maxAns);
        maxAns=max(ansTwo,maxAns);
        maxAns=max(ansThree,maxAns);
    }
         if (maxAns == ansOne) answer.push_back(1);
        if (maxAns == ansTwo) answer.push_back(2);
        if (maxAns == ansThree) answer.push_back(3);   

    return answer;
}