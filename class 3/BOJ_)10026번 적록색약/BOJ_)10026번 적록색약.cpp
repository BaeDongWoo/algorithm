/*BOJ_)10026번 적록색약
		b_d_o_o			*/
#include<iostream>
#include<string>
using namespace std;
string red_Green[100][100];
bool check[100][100] = { 0, };
bool check_RGB[100][100] = { 0, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N;
int cnt = 0;
int cnt_RGB = 0;
void BFS(int x, int y);
void BFS_RGB(int x, int y);
int main() {
	string a;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> a;
		for (int j = 0;j < N;j++) {
			red_Green[i][j]=a[j];
		}
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (check[i][j] == 0) {
				BFS(i, j);
				cnt++;
			}
			if (check_RGB[i][j] == 0) {
				BFS_RGB(i, j);
				cnt_RGB++;
			}
		}
	}
	cout << cnt<<" "<<cnt_RGB;
	return 0;
}
void BFS(int x, int y) {
	check[x][y] = 1;
	string RGB = red_Green[x][y];
	for (int i = 0;i < 4;i++) {
		int X = x + dx[i];
		int Y = y + dy[i];
		if (X >= 0 && X < N && Y >= 0 && Y < N) {
			if (check[X][Y] == 0) {
				string nextRGB = red_Green[X][Y];
				if (RGB == red_Green[X][Y]) {
					BFS(X, Y);
				}
			}
		}
	}
}

void BFS_RGB(int x, int y) {
	check_RGB[x][y] = 1;
	string RGB = red_Green[x][y];
	for (int i = 0;i < 4;i++) {
		int X = x + dx[i];
		int Y = y + dy[i];
		if (X >= 0 && X < N && Y >= 0 && Y < N) {
			if (check_RGB[X][Y] == 0) {
				string nextRGB = red_Green[X][Y];
				if (RGB == "G" || RGB == "R") {
					if (nextRGB == "G" || nextRGB == "R") {
						BFS_RGB(X, Y);
					}
				}
				else {
					if (RGB == nextRGB) {
						BFS_RGB(X, Y);
					}
				}
			}
		}
	}
}