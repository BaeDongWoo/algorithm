/*BOJ_)5525¹ø IOIOI
		b_d_o_o		*/
#include <iostream>
#include <string>
using namespace std;
int main() {
	int N, M;
	int cnt = 0;
	string S;
	cin >> N >> M >> S;
	for (int i = 0;i < M;i++) {
		if (S[i] == 'I') {
			int a = 0;
			while (S[i + 1] == 'O' && S[i + 2] == 'I') {
				a++;
				i += 2;
				if (a == N) {
					cnt++;
					a--;
				}
			}
		}
	}
	cout << cnt;
}