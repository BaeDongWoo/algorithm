/*BOJ_)1992번 쿼드트리
		b_d_o_o		*/
#include <iostream>
#include <string>
using namespace std;
int N;
int quadTree[64][64];
void quad(int x, int y, int n);
int main() {
	string a;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> a;
		for (int j = 0;j < N;j++) {
			quadTree[i][j]=a[j]-48;
		}
	}
	quad(0, 0, N);
}
void quad(int x, int y, int n) {
	quadTree[x][y];
	for (int i = x;i < x+n;i++) {
		for (int j = y;j < y+n;j++) {
			if (quadTree[i][j] != quadTree[x][y]) {
				cout << "(";
				quad(x, y, n / 2);
				quad(x , y + n / 2, n / 2);
				quad(x + n / 2, y , n / 2);
				quad(x + n / 2, y + n / 2, n / 2);
				cout << ")";
				return;
			}
		}
	}
	if (quadTree[x][y] == 1) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}