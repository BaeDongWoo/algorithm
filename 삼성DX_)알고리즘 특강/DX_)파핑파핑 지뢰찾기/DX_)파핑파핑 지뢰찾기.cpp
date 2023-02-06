/*DX_)파핑파핑 지뢰찾기
		b_d_o_o		*/
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;
const int MAXN = 300;
int matrix[MAXN][MAXN];
vector<pair<int,int>> v;
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };
int N;
int result=0;
int cnt = 0;
int click = 0;
void BFS();
void checkAround(int x, int y);
bool check(int x, int y);
void init();
int main() {
	int T;
	cin >> T;
	for (int testcase = 1;testcase <= T;testcase++) {
		init();
		string input;
		cin >> N;
		for (int i = 0;i < N;i++) {
			cin >> input;
			for (int j = 0;j < N;j++) {\
				if (input[j] == '.') {
					matrix[i][j] = 999;
				}
				else {
					matrix[i][j] = -1;
				}
				if (input[j] == '.') {
					v.push_back(make_pair(i, j));
				}
			}
		}
		BFS();
		result = (v.size() - cnt) + click;
		cout <<"#"<<testcase<<" "<< result << '\n';
	}
	return 0;
}
void init() {
	click = 0;
	cnt = 0;
	result = 0;
	memset(matrix, 0, sizeof(matrix));
	v.clear();
}
void BFS() {
	for (int i = 0;i < v.size();i++) {
		int X = v[i].first;
		int Y = v[i].second;
		if (matrix[X][Y] == 999) {//.이면
			if (check(X,Y)) {
				click++;
				checkAround(X, Y);
			}
		}
	}
}
bool check(int x, int y) {
	int poppingCnt = 0;
	for (int i = 0;i < 8;i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];
		if (newX >= 0 && newY >= 0 && newX < N && newY < N) {
			if (matrix[newX][newY] == -1) {
				poppingCnt++;
			}
		}
	}
	if (poppingCnt == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
void checkAround(int x, int y) {
	matrix[x][y] = 0;
	cnt++;
	for (int j = 0;j < 8;j++) {
		int nextX = x + dx[j];
		int nextY = y + dy[j];
		if (nextX >= 0 && nextY >= 0 && nextX < N && nextY < N) {
			if (matrix[nextX][nextY] == 999) {
				if (check(nextX, nextY)) {
					checkAround(nextX, nextY);
				}
				else {
					matrix[nextX][nextY] = 3;
					cnt++;
				}
			}
		}
	}
}
