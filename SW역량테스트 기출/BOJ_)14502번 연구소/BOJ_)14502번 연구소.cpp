/*BOJ_)14502번 연구소
		b_d_o_o		*/
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include<string.h>
using namespace std;
void bfs();
void run(int x, int y, int cnt);
int checkSafetyArea();
vector <pair<int, int>> v;
int N, M;
int result = 0;
int matrix[8][8];
int visit[8][8] = { 0, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] == 2) {
				v.push_back(make_pair(i, j));
			}
		}
	}
	run(0, 0, 0);
	cout << result;
}

void run(int x, int y, int cnt) {// 벽을 세우는 조합
	if (cnt == 3) {
		bfs();
		int num = checkSafetyArea();
		result = max(result, num);
		memset(visit, 0, sizeof(visit));
		return;
	}
	for (int i = x; i < N; i++) {
		for (int j = y; j < M; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][j] = 1;
				run(0, 0, cnt + 1);
				matrix[i][j] = 0;
			}
		}
	}
}

void bfs() {
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		queue <pair<int, int>> q;
		q.push(make_pair(x, y));
		while (!q.empty()) {
			int nx = q.front().first;
			int ny = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int NX = nx + dx[j];
				int NY = ny + dy[j];
				if (NX >= 0 && NX < N && NY >= 0 && NY < M) {
					if (matrix[NX][NY] == 0) {
						if (visit[NX][NY] == 0) {
							visit[NX][NY] = 2;
							q.push(make_pair(NX, NY));
						}
					}
				}
			}
		}
	}

}
int checkSafetyArea() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] != 2 && matrix[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}