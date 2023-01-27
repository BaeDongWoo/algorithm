/*BOJ_)14499번 주사위 굴리기
			b_d_o_o			*/
#include <iostream>
#include <utility>
using namespace std;
int matrix[21][21];
int N, M, r, c, k;
int diceFront = 1;
int diceBack = 6;
int diceRight = 3;
int diceLeft = 4;
int diceTop = 2;
int diceBottom = 5;
int dice[7];
void diceDirection(int A);
void diceCopy(int x, int y, int top);
void dicePrint(int Top);
int main() {
	cin >> N >> M >> r >> c >> k;
	for (int i = 0;i < N;i++) {//배열에 상태 저장
		for (int j = 0;j < M;j++) {
			cin >> matrix[i][j];
		}
	}
	int a;
	for (int i = 0;i < k;i++) {
		cin >> a;
		diceDirection(a);
	}
	return 0;
}
void diceDirection(int A) {
	int F, B, Bo, T, R, L;
	F = diceFront;
	B = diceBack;
	Bo = diceBottom;
	T = diceTop;
	R = diceRight;
	L = diceLeft;
	if (A == 1) {
		c=c + 1;
		if (c > M - 1) {
			c = M-1;
			return;
		}
		diceFront = L;
		diceBack = R;
		diceRight = F;
		diceLeft = B;
	}
	else if (A == 2) {
		c=c - 1;
		if (c < 0) {
			c = 0;
			return;
		}
		diceFront = R;
		diceBack = L;
		diceRight = B;
		diceLeft = F;
	}
	else if (A == 3) {
		r=r - 1;
		if (r < 0) {
			r = 0;
			return;
		}
		diceFront = Bo;
		diceBack = T;
		diceBottom = B;
		diceTop = F;
	}
	else if (A == 4) {
		r=r + 1;
		if (r > N - 1) {
			r = N-1;
			return;
		}
		diceFront = T;
		diceBack = Bo;
		diceBottom = F;
		diceTop = B;
	}
	return diceCopy(r,c,diceFront);
}
void diceCopy(int x,int y,int Front) {
	dicePrint(Front);
	if (matrix[x][y] != 0) {
		dice[7 - Front] = matrix[x][y];
		matrix[x][y] = 0;
	}
	else {
		matrix[x][y] = dice[7 - Front];
	}
	return;
}
void dicePrint(int Front) {
	cout << dice[Front]<<'\n';
	return;
}