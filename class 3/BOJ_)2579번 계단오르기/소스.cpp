/*BOJ_) 2579번 계단오르기 
		b_d_o_o			*/
#include <iostream>
using namespace std;
const int MAXN = 300;
int st[MAXN];
int main() {
	int N;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> st[i];
	}
	int total_z[MAXN]={0,};
	int total_o[MAXN]={0,};
	int total_t[MAXN]={0,};
	total_z[1] = 0;
	total_o[1] = st[1];
	for (int i = 2;i <= N;i++) {
		total_z[i] = max(total_o[i - 1], total_t[i - 1]);
		total_o[i] = total_z[i - 1] + st[i];
		total_t[i] = total_o[i - 1] + st[i];
	}
	cout << max(total_o[N], total_t[N]);
	return 0;
}