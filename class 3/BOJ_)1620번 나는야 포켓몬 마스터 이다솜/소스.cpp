/*BOJ_)나는야 포켓몬 마스터 이다솜
			b_d_o_o				*/
#include <iostream>
#include <utility>
#include <string>
#include <map>
using namespace std;
int N, M;
string input;
map<string, string>m;
map<string, string>n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		cin >> input;
		m.insert(pair<string, string>(input, to_string(i)));
		n.insert(pair<string, string>(to_string(i), input));
	}
	for (int i = 1; i <= M;i++) {
		cin >> input;
		if (input > "A") {
			cout << m[input] << '\n';
		}
		else {
			cout << n[input] << '\n';
		}
	}
	return 0;
}