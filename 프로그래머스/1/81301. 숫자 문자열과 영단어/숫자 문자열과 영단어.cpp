#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    map<string,int> setString;
    for(int i =0;i<10;i++){
        setString.insert({arr[i],i});
    };
    string stringAns;
    string temp;
    for(int i =0;i<s.size();i++){
        if(s[i]-'0'>=0 && s[i]-'0'<=9) {
            stringAns+=s[i];
        }
        else{
            temp += s[i];
            if(setString.find(temp)!=setString.end()){
                stringAns+=to_string(setString[temp]);
                temp="";
            }
        }
    }
    answer=stoi(stringAns);
    return answer;
}