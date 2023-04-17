/*BOJ_)16174�� ������ �f��
		b_d_o_o		*/
//�׷���
//���� or �Ʒ�
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
bool bfs(int x, int y);
queue <pair<int,int>> q;
int arr[64][64];
int visit[64][64];
int N;
int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}
	if (bfs(0, 0)) cout << "HaruHaru";
	else cout << "Hing";
}
bool bfs(int x, int y) {
	q.push(make_pair(x, y));
	visit[x][y] = 1;
	while (!q.empty()) {
		int X = q.front().first;
		int Y = q.front().second;
		q.pop();
		int leng = arr[X][Y];
		if (leng == -1) return true;
		int nX = X + leng;
		int nY = Y + leng;
		if (nX < N) {
			if (visit[nX][Y] == 0) {
				visit[nX][Y] = 1;
				q.push(make_pair(nX, Y));
			}
		}
		if (nY < N) {
			if (visit[X][nY] == 0) {
				visit[X][nY] = 1;
				q.push(make_pair(X, nY));
			}
		}
	}
	return false;
}