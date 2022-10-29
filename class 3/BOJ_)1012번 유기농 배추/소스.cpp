/*BOJ_)1012번 유기농 배추 
		b_d_o_o			*/
#include <iostream>
#include <vector>
#include <utility>

using namespace std;
const int MAXN = 2500;

pair<int, int> x_y[MAXN];
int idx[4][2] = { {1,0},{-1,0},{0,1} ,{0,-1} };
bool vi[50][50] = {0,};
void Vi(int a,int b);
int main() {
	int T, M, N, K;
	int n, m;
	cin >> T;

	while (T--) {
		int cnt = 0;
		cin >> M >> N >> K;
		for (int i = 0;i < K;i++) {
			cin >> n >> m;//배추가 심어진 위치
			x_y[i].first = n;
			x_y[i].second = m;
			vi[n][m] = 1;//배추가 심어진 위치 저장
		}
		for (int i = 0;i < K;i++) {
			if (vi[x_y[i].first][x_y[i].second] == 1) {
				cnt++;
				Vi(x_y[i].first, x_y[i].second);
			}
		}
		cout << cnt<<'\n';
	}
	return 0;
}

void Vi(int a,int b) {
	if (vi[a][b] == 1) {
		vi[a][b] = 0;//방문처리
		for (int i = 0;i < 4;i++) {
			int x =a+ idx[i][0];
			int y =b+ idx[i][1];
			if (x >= 0 && y >= 0) {
				Vi(x , y);
			}
		}
	}	
	return;
}