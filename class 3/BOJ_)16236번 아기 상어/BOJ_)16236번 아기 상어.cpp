/*BOJ_)16236번 아기 상어
		b_d_o_o		*/
#include <iostream>
#include<utility>
#include<vector>
#include<tuple>
#include<queue>
#include <functional>
using namespace std;
int matrix[20][20];
vector<pair<int, pair<int, int>>> targetList;
pair<int, int>babyShark;
int N, M;
int babySharkSize = 2;
int cnt = 0;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int result = 0;
int BFS(int x, int y);
int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> M;
			matrix[i][j] = M;
			if (M == 9) {
				matrix[i][j] = 0;
				babyShark.first = i;
				babyShark.second = j;
			}
		}
	}
	while (BFS(babyShark.first, babyShark.second)) {
		BFS(babyShark.first, babyShark.second);
	}
	cout << result;
}

int BFS(int x, int y) {
	bool check[20][20] = { 0, };
	check[x][y] = 1;
	int time = 0;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
	q.push(make_pair(time, make_pair(x, y)));
	while (!q.empty()) {
		int sharkX = q.top().second.first;
		int sharkY = q.top().second.second;
		int t = q.top().first;
		q.pop();
		if (matrix[sharkX][sharkY] != 0 && matrix[sharkX][sharkY] < babySharkSize) {
			cnt++;
			babyShark.first = sharkX;
			babyShark.second = sharkY;
			result += t;
			matrix[sharkX][sharkY] = 0;
			if (cnt == babySharkSize) {
				cnt = 0;
				babySharkSize++;
			}
			return 1;
		}
		for (int i = 0;i < 4;i++) {
			int newSharkX = sharkX + dx[i];
			int newSharkY = sharkY + dy[i];
			if (newSharkX >= 0 && newSharkX < N && newSharkY >= 0 && newSharkY < N) {
				int fish = matrix[newSharkX][newSharkY];
				if (babySharkSize >= fish) {
					if (check[newSharkX][newSharkY] == 0) {
						check[newSharkX][newSharkY] = 1;
						q.push(make_pair(t + 1, make_pair(newSharkX, newSharkY)));
					}
				}
			}
		}
	}
	if (q.empty()) {
		return 0;
	}
}