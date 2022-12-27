/*BOJ_)7569번 토마토
		b_d_o_o		*/
#include<iostream>
#include<vector>
#include<utility>
using namespace std;

const int MAXN = 100;
int check[MAXN][MAXN][MAXN] = { 0, };
vector<pair<int, pair<int, int>>> tomato[MAXN * MAXN * MAXN];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int dz[2] = { 1,-1 };
int cnt = 0;
int day = 0;
void BFS(int a, int z, int m, int n);
int main() {
	int N, M, Z;
	int a = 0;
	cin >> N >> M >> Z;
	int num = N * M * Z;
	for (int i = 0;i < Z;i++) {
		for (int j = 0;j < M;j++) {
			for (int k = 0;k < N;k++) {
				cin >> check[i][j][k];
				if (check[i][j][k] == 1) {
					tomato[0].push_back(make_pair(i, make_pair(j, k)));
					cnt++;
				}
				else if (check[i][j][k] == -1) {
					num--;
				}
			}
		}
	}
	while (!tomato[a].empty()) {
		BFS(a,Z,M,N);
		a++;
	}
	if (num == cnt) {
		cout << day - 1;
	}
	else {
		cout << -1;
	}
	return 0;
}
void BFS(int a, int z, int m, int n) {
	day++;
	for (int i = 0;i < tomato[a].size();i++) {
		for (int j = 0;j < 4;j++) {
			int Z = tomato[a][i].first;
			int x = tomato[a][i].second.first + dx[j];
			int y = tomato[a][i].second.second + dy[j];
			if (x >= 0 && x < m && y >= 0 && y < n) {
				if (check[Z][x][y] == 0) {
					check[Z][x][y] = 1;
					tomato[a + 1].push_back(make_pair(Z, make_pair(x, y)));
					cnt++;
				}
			}
		}
		for (int j = 0;j < 2;j++) {
			int Z = tomato[a][i].first + dz[j];
			int x = tomato[a][i].second.first;
			int y = tomato[a][i].second.second;
			if (Z >= 0 && Z < z) {
				if (check[Z][x][y] == 0) {
					check[Z][x][y] = 1;
					tomato[a + 1].push_back(make_pair(Z, make_pair(x, y)));
					cnt++;
				}
			}
		}
	}
	return;
}