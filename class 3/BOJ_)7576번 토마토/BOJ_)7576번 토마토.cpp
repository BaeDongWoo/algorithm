/*BOJ_)7576번 토마토
		b_d_o_o		*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
const int MAXN = 1000;
vector<pair<int,int>> v[MAXN*MAXN];
int check[MAXN][MAXN];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int cnt = 0;
int day = 0;
void bfs(int a, int n, int m);
int main() {
	int N, M, t_num;
	int a = 0;
	cin >> N >> M;
	int check_num=N*M;
	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			cin >> t_num;
			check[i][j] = t_num;
			if (t_num == 1) {
				v[0].push_back(make_pair(i, j));
				cnt++;
			}
			if (t_num == -1) {
				check_num--;
			}
		}
	}
	while (v[a].size() != 0) {
		bfs(a,M,N);
		a++;
	}
	if (check_num == cnt) {
		cout << day-1;
	}
	else {
		cout << -1;
	}
	return 0;
}

void bfs(int a,int m,int n) {
	day++;
	int b = a+1;
	for (int i = 0;i < v[a].size();i++) {
		for (int j = 0;j < 4;j++) {
			int x = v[a][i].first + dx[j];
			int y = v[a][i].second + dy[j];
			if(x>=0&&x<m&&y>=0&&y<n){
				if (check[x][y] == 0) {
					check[x][y] = 1;
					v[b].push_back(make_pair(x, y));
					cnt++;
				}
			}
		}
	}
	return;
}
