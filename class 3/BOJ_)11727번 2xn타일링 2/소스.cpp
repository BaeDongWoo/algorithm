/*BOJ_)11727번 2xn타일링 2
		b_d_o_o			*/
#include <iostream>
using namespace std;
const int MAXN = 1000;
int a[MAXN];
int main() {
	int n;
	a[1] = 1;
	a[2] = 3;
	a[3] = 5;
	cin >> n;
	for (int i = 4;i <= n;i++) {
		a[i] = (a[i - 1] + (a[i - 2]*2))%10007;
	}
	cout << a[n];
	return 0;
}