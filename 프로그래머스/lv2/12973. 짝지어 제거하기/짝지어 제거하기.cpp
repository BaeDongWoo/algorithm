#include <iostream>
#include <string>
#include <stack>

using namespace std;
stack <char> ss;

int solution(string s)
{
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(ss.empty()) ss.push(s[i]);
        else{
            if(ss.top()==s[i]) ss.pop();
            else ss.push(s[i]);
        }
    }
    if(ss.empty())ans=1;

	return ans;
}
