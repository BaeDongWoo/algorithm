/*BOJ_)2178¹ø ¹Ì·ÎÅ½»ö
		b_d_o_o		*/
#include<iostream>
#include<string>
#include<queue>
using namespace std;
int maze[101][101] = { 0, };
bool visit[101][101];
int moveCheck[101][101];
void BFS(int x, int y);
int N, M;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int result = 999999;
int cnt = 1;
int main() {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		string input;
		cin >> input;
		
		for (int j = 0;j < M;j++) {
			maze[i][j] = input[j] - 48;
		}
	}
	BFS(0, 0);
	cout << moveCheck[N - 1][M - 1];
	return 0;
}

void BFS(int x, int y) {
	visit[x][y] = 1;
	moveCheck[x][y]++;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int X = q.front().first;
		int Y = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int newX = X + dx[i];
			int newY = Y + dy[i];
			if (newX >= 0 && newX < N && newY >= 0 && newY < M) {
				if (maze[newX][newY] == 1&& visit[newX][newY]==0) {
					visit[newX][newY] = 1;
					moveCheck[newX][newY] = moveCheck[X][Y] + 1;
					q.push(make_pair(newX, newY));
				}
			}
		}
	}
}