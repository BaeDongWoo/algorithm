/*BOJ_)2630번 색종이 만들기
		b_d_o_o			*/
#include <iostream>
using namespace std;
int arr[128][128];
int W ;
int B ;
void compare(int x, int y, int n);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}
	compare(0, 0, N);
	cout << W << '\n' << B;
	return 0;
}
void compare(int x, int y, int n) {
	int c = arr[x][y];
	for (int i = x;i < x + n;i++) {
		for (int j = y;j < y + n;j++) {
			if (c != arr[i][j]) {
				compare(x, y, n / 2);
				compare(x, y + n / 2, n / 2);
				compare(x + n / 2, y, n / 2);
				compare(x + n / 2, y + n / 2, n / 2);
				return ;
			}
		}
	}
	if (c == 1) {
		B++;
	}
	else {
		W++;
	}
}