/*BOJ_)2xn≈∏¿œ∏µ		
	b_d_o_o		*/
#include<iostream>
using namespace std;
const int MAXN = 1001;
long long a[MAXN];
int main() {
	int n;
	cin >> n;
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;

	for (int i = 4;i <= n;i++) {
		a[i] = (a[i - 1] + a[i - 2])%10007;
	}
	cout << a[n];
}