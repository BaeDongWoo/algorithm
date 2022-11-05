/*BOJ_) 11047¹ø µ¿Àü 0
		b_d_o_o		*/
#include <iostream>
using namespace std;

int main() {
	int N, K;
	int A[11];
	int cnt = 0;
	int M;
	cin >> N >> K;
	for (int i = 1;i <= N;i++) {
		cin >> A[i];
	}
	for (int i = N;i >= 1;i--) {
		if (A[i] <= K) {
			cnt = K / A[i];
			M = K % A[i];
			while (M % A[i] != 0) {
				i--;
				if (A[i] <= M) {
					cnt += M / A[i];
					M = M % A[i];
				}
			}
			cout << cnt;
		}
		if (cnt != 0) {
			break;
		}
	}
	return 0;
}