/*BOJ_)9461�� �ĵ��� ����
		b_d_o_o		 */
#include <iostream>
using namespace std;
const int MAXN = 101;
long long a[MAXN];
int main() {
	int T;
	int N;
	cin >> T;
	while (T--) {
		cin >> N;
		a[1] = 1;
		a[2] = 1;
		a[3] = 1;
		for (int i = 4;i <= N;i++) {
			a[i] = a[i - 2] + a[i - 3];
		}
		cout << a[N]<<'\n';
	}
	return 0;
}