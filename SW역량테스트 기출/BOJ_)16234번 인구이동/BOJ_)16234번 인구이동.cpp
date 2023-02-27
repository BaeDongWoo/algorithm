/*BOJ_)16234번 인구이동
		b_d_o_o		*/
#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
queue <pair<int, int>> qq;
int matrix[50][50];
int visit[50][50];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int score;
int cnt;
int result;
int N, L, R;
bool checkMatrix();
void findIdx();
void changeNum();
void bfs(int x, int y);
int main() {
	cin >> N>> L>> R;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			int num;
			cin >> num;
			matrix[i][j] = num;
		}
	}
	while (checkMatrix()) {
		result++;
		findIdx();
		memset(visit, 0, sizeof(visit));
	}
	cout << result;
	return 0;
}

bool checkMatrix() {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			int s = matrix[i][j];
			for (int k = 0;k < 4;k++) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (x >= 0 && x < N && y >= 0 && y < N) {
					int c = matrix[x][y];
					int g = abs(s - c);
					if (g >= L && g <= R) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

void findIdx() {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (visit[i][j] == 0) {
				bfs(i, j);
				changeNum();
			}
		}
	}
}

void bfs(int x, int y) {
	visit[x][y] = 1;
	score = 0;
	cnt = 0;
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int X = q.front().first;
		int Y = q.front().second;
		q.pop();
		qq.push(make_pair(X, Y));
		score += matrix[X][Y];
		cnt++;
		int s = matrix[X][Y];
		for (int i = 0;i < 4;i++) {
			int nx = X + dx[i];
			int ny = Y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				int c = matrix[nx][ny];
				int g = abs(s - c);
				if (visit[nx][ny] == 0&& g >= L && g <= R) {
					visit[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void changeNum() {
	int reNum = floor(score / cnt);
	while (!qq.empty()) {
		int x = qq.front().first;
		int y = qq.front().second;
		matrix[x][y] = reNum;
		qq.pop();
	}
}