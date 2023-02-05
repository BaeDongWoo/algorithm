/*DX_)프로세서 연결하기
		b_d_o_o		*/
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;
vector<pair<int, int>> v;
int matrix[13][13];
int check[13][13];
int dire[4] = { 1,2,3,4 };//1부터 동쪽으로 시계방향 회전
int matrixSize;
int CNT = 0;//core의 갯수
int result = 987654321;//전선의 길이
void DFS(int idx, int cnt, int line);
bool checkProcessor(int x, int y, int D);//해당 방향으로 전선이 끝까지 이동할 수 있는지 확인
int checkMatrix(int x, int y, int D);//checkProcessor가 ture라면 진행 방향을 체크
void removeMatrix(int x, int y, int D);//진행방향을 뒤로 백트래킹
int main() {
	int T;
	cin >> T;
	for (int testcase = 1;testcase <= T;testcase++) {
		memset(matrix, 0, sizeof(matrix));
		CNT = 0;
		result = 987654321;
		v.clear();
		cin >> matrixSize;
		for (int i = 0;i < matrixSize;i++) {
			for (int j = 0;j < matrixSize;j++) {
				cin >> matrix[i][j];
				if (matrix[i][j] == 1) {
					v.push_back(make_pair(i, j));
				}
			}
		}
		DFS(0, 0, 0);
		cout << "#" << testcase << " " << result << '\n';
	}
	return 0;
}
void DFS(int idx, int cnt, int line) {
	for (int i = idx;i < v.size();i++) {
		int x = v[i].first;
		int y = v[i].second;
		if (x != 0 && x != matrixSize - 1 && y != 0 && y != matrixSize - 1) {
			for (int j = 0;j < 4;j++) {
				if (checkProcessor(x, y, dire[j])) {
					int C = cnt + 1;
					int Line = line + checkMatrix(x, y, dire[j]);
					if (C > CNT) {
						CNT = C;
						result = Line;
					}
					else if (C == CNT) {
						result = min(result, Line);
					}
					DFS(i + 1, C, Line);
					removeMatrix(x, y, dire[j]);
				}
			}
		}
	}
}
void removeMatrix(int x, int y, int D) {
	check[x][y] = 0;
	int dx;
	int dy;
	if (D == 1) {
		dx = 0;
		dy = 1;
	}
	else if (D == 2) {
		dx = 1;
		dy = 0;
	}
	else if (D == 3) {
		dx = 0;
		dy = -1;
	}
	else if (D == 4) {
		dx = -1;
		dy = 0;
	}
	while (true) {
		x += dx;
		y += dy;
		check[x][y] = 0;
		if (x == 0 || x == matrixSize - 1 || y == 0 || y == matrixSize - 1) {
			return;
		}
	}
}
int checkMatrix(int x, int y, int D) {
	check[x][y] = 1;
	int Line = 0;
	int dx;
	int dy;
	if (D == 1) {
		dx = 0;
		dy = 1;
	}
	else if (D == 2) {
		dx = 1;
		dy = 0;
	}
	else if (D == 3) {
		dx = 0;
		dy = -1;
	}
	else if (D == 4) {
		dx = -1;
		dy = 0;
	}
	while (true) {
		x += dx;
		y += dy;
		Line++;
		check[x][y] = 1;
		if (x == 0 || x == matrixSize - 1 || y == 0 || y == matrixSize - 1) {
			return Line;
		}
	}
}
bool checkProcessor(int x, int y, int D) {
	int dx;
	int dy;
	if (D == 1) {
		dx = 0;
		dy = 1;
	}
	else if (D == 2) {
		dx = 1;
		dy = 0;
	}
	else if (D == 3) {
		dx = 0;
		dy = -1;
	}
	else if (D == 4) {
		dx = -1;
		dy = 0;
	}
	while (true) {
		x += dx;
		y += dy;
		if (matrix[x][y] != 0 || check[x][y] != 0) {
			return false;
		}
		if (x == 0 || x == matrixSize - 1 || y == 0 || y == matrixSize - 1) {
			return true;
		}
	}
}