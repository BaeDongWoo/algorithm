/*BOJ_)1764¹ø µèº¸Àâ
		b_d_o_o		*/
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v;
map<string, string> N_str;
int main() {
	int N, M;
	string s;
	cin >> N >> M;
	while (N--) {
		cin >> s;
		N_str[s] = s;
	}
	int cnt = 0;
	while (M--) {
		cin >> s;
		if (s == N_str[s]) {
			v.push_back(s);
			cnt++;
		}
	}
	sort(v.begin(), v.end());
	cout << cnt<<'\n';
	for (int i = 0; i < v.size();i++) {
		cout << v[i]<<'\n';
	}
	return 0;
}