/*BOJ_)6064¹ø Ä«À× ´Þ·Â
		b_d_o_o			*/
#include <iostream>
using namespace std;
const int MAXN = 40000;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	int N, M, X, Y;
	int result;
	cin >> T;
	while (T--) {
		cin >> N >> M >> X >> Y;
		int A,B,C;
		A = N;
		B = M;
		int D=N*M;
		bool check = 0;
		while (B) {
			C = A % B;
			A = B;
			B = C;
		}
		int MAX = D / A;
		for (int i = X;i <= MAX;i+=N) {
			int MY = i % M;
			if (MY == 0) {
				MY = M;
			}
			if (MY==Y) {
				result = i;
				check = 1;
				break;
			}
			
		}
		if (check == 0) {
			result = -1;
		}
		cout << result<<'\n';
	}
}