#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <map>
using namespace std;
int idx = 0;
map<string, int> m;
stack <string> s;
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
     s.push(words[0]);
	m[words[0]]++;
	for (int i = 1; i < words.size(); i++) {
		string w = s.top();
		int wl = s.top().length() - 1;
		string ww = words[i];
		if (s.top()[wl] != ww[0]) {
			idx = i;
			break;
		}
		else s.push(words[i]);
		if (m[words[i]] != 0) {
			idx = i;
			break;
		}
		else m[words[i]]++;
	}
    if(idx==0){
       answer.push_back(0);
    answer.push_back(0);
    }
    else{
        int turn = (idx / n) + 1;
	int a = (idx % n) + 1;
    answer.push_back(a);
    answer.push_back(turn);
    }
    return answer;
}