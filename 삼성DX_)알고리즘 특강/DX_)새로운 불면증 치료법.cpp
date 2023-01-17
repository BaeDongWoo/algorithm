/*DX_)새로운 불면증 치료법
		b_d_o_o		*/
#include <iostream>
using namespace std;
int main() {
	int T;
	int num;
	cin >> T;
	for (int i = 1;i <= T;i++) {
		bool check[10] = { 0, };
		int numPlus = 0;
		int tmp;
		cin >> num;
		while (true) {
			bool arrCheck = 0;
			numPlus += num;
			tmp = numPlus;
			while (tmp > 0) {
				check[tmp % 10] = 1;
				tmp /= 10;
			}
			for (int j = 0;j < 10;j++) {
				if (check[j] == 0) {
					arrCheck = 1;
				}
			}
			if (arrCheck==0) {
				cout << '#' << i << ' ' << numPlus << '\n';
				break;
			}		
		}
	}
	return 0;
}