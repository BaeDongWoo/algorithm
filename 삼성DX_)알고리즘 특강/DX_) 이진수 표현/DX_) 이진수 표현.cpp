/*DX_) 이진수 표현
	  b_d_o_o	*/
#include<iostream>
using namespace std;
int main() {
	int TC;
	int N, M;
	cin >> TC;
	for (int i = 1;i <= TC;i++) {
		cin >> N >> M;
		int cnt = 0;
		for (int j = 0;j < N;j++) {
			if (M >> j & 1 ) {
				cnt++;
			}
			else {
				cout << "#" << i << " " << "OFF" << '\n';
				break;
			}
		}
		if (cnt == N) {
			cout <<"#" << i << " " << "ON" << '\n';
		}
	}
}
