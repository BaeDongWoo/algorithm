/*BOJ_)5525¹ø IOIOI
		b_d_o_o		*/
#include <iostream>
#include <string>
using namespace std;
int main() {
	int N, M;
	int cnt = 0;
	string S;
	cin >> N>>M>>S;
	for (int i = 0;i < M;i++) {
		if (S[i] == 'I') {
			int a = 0;
			int b = i;
			while (a != N) {
				a++;
				if (S[b + 1] == 'O' && S[b + 2] == 'I') {
					if (a == N) {
						cnt++;
					}
					else {
						b += 2;
					}
				}
				else {
					break;
				}
			}
		}
	}
	cout << cnt;
}