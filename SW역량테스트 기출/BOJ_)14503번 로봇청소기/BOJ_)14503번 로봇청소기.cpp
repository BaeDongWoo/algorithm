/*BOJ_)14503번 로봇청소기
		b_d_o_o		*/
#include <iostream>
using namespace std;
int check[51][51];
int result = 0;
void clean(int x, int y, int d);
void find(int X, int Y, int D);
int main() {
	int N, M;
	int r, c, d;
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0;i < N;i++) {//격자 배열에 집의 상태 입력
		for (int j = 0;j < M;j++) {
			cin >> check[i][j];
		}
	}
	clean(r, c, d);
	cout << result;
	return 0;
}

void clean(int x,int y,int d) {
	check[x][y] = 2;
	result++;
	find(x, y, d);
}

void find(int X,int Y,int D) {
	if (D == 0) {//북쪽
		int dx[4] = { 0,1,0,-1 };
		int dy[4] = { -1,0,1,0 };
		for(int i=0;i<4;i++){
			int newX = X + dx[i];
			int newY = Y + dy[i];
			if (check[newX][newY] == 0) {
				if (dy[i] == -1) {//D의 방향 재설정
					D = 3;
				}
				else if (dx[i] == 1) {
					D = 2;
				}
				else if (dy[i] == 1) {
					D = 1;
				}
				else {
					D = 0;
				}
				return clean(newX, newY, D);
			}
		}
		if (check[X+1][Y] != 1) {
			return find(X+1, Y, D);
		}
		else {
			return;
		}
	}
	else if (D == 3) {
		int dx[4] = { 1,0,-1,0 };
		int dy[4] = { 0,1,0,-1 };
		for (int i = 0;i < 4;i++) {
			int newX = X + dx[i];
			int newY = Y + dy[i];
			if (check[newX][newY] == 0) {
				if (dy[i] == -1) {//D의 방향 재설정
					D = 3;
				}
				else if (dx[i] == 1) {
					D = 2;
				}
				else if (dy[i] == 1) {
					D = 1;
				}
				else {
					D = 0;
				}
				return clean(newX, newY, D);
			}
		}
		if (check[X][Y+1] != 1) {
			return find(X, Y+1, D);
		}
		else {
			return;
		}
	}
	else if (D == 2) {
		int dx[4] = { 0,-1,0,1 };
		int dy[4] = { 1,0,-1,0 };
		for (int i = 0;i < 4;i++) {
			int newX = X + dx[i];
			int newY = Y + dy[i];
			if (check[newX][newY] == 0) {
				if (dy[i] == -1) {//D의 방향 재설정
					D = 3;
				}
				else if (dx[i] == 1) {
					D = 2;
				}
				else if (dy[i] == 1) {
					D = 1;
				}
				else {
					D = 0;
				}
				return clean(newX, newY, D);
			}
		}
		if (check[X-1][Y] != 1) {
			return find(X-1 , Y, D);
		}
		else {
			return;
		}

	}
	else if (D == 1) {
		int dx[4] = { -1,0,1,0 };
		int dy[4] = { 0,-1,0,1 };
		for (int i = 0;i < 4;i++) {
			int newX = X + dx[i];
			int newY = Y + dy[i];
			if (check[newX][newY] == 0) {
				if (dy[i] == -1) {//D의 방향 재설정
					D = 3;
				}
				else if (dx[i] == 1) {
					D = 2;
				}
				else if (dy[i] == 1) {
					D = 1;
				}
				else {
					D = 0;
				}
				return clean(newX, newY, D);
			}
		}
		if (check[X][Y-1] != 1) {
			return find(X, Y-1, D);
		}
		else {
			return;
		}

	}
}