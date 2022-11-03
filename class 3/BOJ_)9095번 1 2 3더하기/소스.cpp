/*BOJ_)9095번 1,2,3더하기
		b_d_o_o			*/
#include <iostream>
using namespace std;
int a[11];
int main() {
	int T, num;
	a[1] = 1;
	a[2] = 2;
	a[3] = 4;
	cin >> T;
	
	for (int i = 0;i < T;i++) {
		cin >> num;
		for (int j = 4;j <= num;j++) {
			a[j] = a[j - 1] + a[j - 2] + a[j - 3];
		}
		cout << a[num]<<'\n';
	}
	return 0;
}