/* BOJ_) 17219�� ��й�ȣ ã��
		b_d_o_o				*/
#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, string> N_str;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	string c,pw;
	cin >> N >> M;
	while (N--) {
		cin >> c>>pw;
		N_str[c] = pw;
	}
	while (M--) {
		cin >> c;
		cout << N_str[c] << '\n';
	}
	return 0;
}