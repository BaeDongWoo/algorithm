#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool compare(string a , string b){
    return a+b>b+a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> stringNum ;
    for(int i = 0;i<numbers.size();i++){
        stringNum.push_back(to_string(numbers[i]));// 모든 숫자를 문자로 변경
    }
    sort(stringNum.begin(),stringNum.end(),compare);
    
    for(int i = 0;i<stringNum.size();i++){
        answer+=stringNum[i];
    }
    if(answer[0]=='0') answer="0";
    return answer;
}


// 맨 앞자리가 큰 수가 앞으로
// 맨 앞자리가 같으면 두번째 자리가 큰 수가 앞으로 
// ...