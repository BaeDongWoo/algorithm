#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(),phone_book.end());
    for(int i = 0;i<phone_book.size()-1;i++){
        int stringSize = phone_book[i].size();
        string str = phone_book[i+1].substr(0,stringSize);
        if(phone_book[i] == str) return false;
    }
    return answer;
}