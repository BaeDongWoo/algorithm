/*BOJ_)11723번 집합
		b_d_o_o		*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int S=0;
int x,M;
string str;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M;
	for (int i = 0;i < M;i++) {
		cin >> str;
		if (str == "add") {
			cin >> x;
			if (S & (1 << x)) {//있을때
			}
			else {
				S |= (1 << x);
			}
		}
		if (str == "remove") {
			cin >> x;
			if (S & (1 << x)) {//있을때
				S &= ~(1 << x);
			}
			else {

			}
		}
		if (str == "check") {
			cin >> x;
			if (S & (1 << x)) {//있을때
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		if (str == "toggle") {
			cin >> x;
			S = S ^ (1 << x);
		}
		if (str == "all") {
			S = (1 << 21) - 1;
		}
		if (str == "empty") {
			S = 0;
		}
	}
	return 0;
}
