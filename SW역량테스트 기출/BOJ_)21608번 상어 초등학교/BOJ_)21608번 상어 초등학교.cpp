/*BOJ_)21608번 상어초등학교
		b_d_o_o		*/
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
const int MAXN = 21;
void search(int I);
void p(int x, int y, int N);
void score();
void s(int num);
int find(int ST, int idx);
pair<int, int> findFR(int x, int y, int idx);
vector <pair<int, int>> v[MAXN * MAXN];
int N;
int result;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int table[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int stu;
	int fav;
	for (int i = 0; i < N * N; i++) {
		cin >> stu;
		for (int j = 0; j < 4; j++) {
			cin >> fav;
			v[i].push_back(make_pair(stu, fav));
		}
	}
	for (int i = 0; i < N * N; i++) {
		search(i);
	}
	score();
	cout << result;
	return 0;
}

void score() {
	for (int i = 0; i < N * N; i++) {
		int st = v[i][0].first;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (table[j][k] == st) {
					p(j, k, i);
				}
			}
		}
	}
}

void p(int x, int y, int n) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		int FF = table[nx][ny];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && FF != 0) {
			for (int j = 0; j < 4; j++) {
				int F = v[n][j].second;
				if (F == FF) {
					cnt++;
				}
			}
		}
	}
	s(cnt);
}
void s(int num) {
	if (num == 1) {
		result += 1;
	}
	else if (num == 2) {
		result += 10;
	}
	else if (num == 3) {
		result += 100;
	}
	else if (num == 4) {
		result += 1000;
	}
}
void search(int I) {
	int B = -1;
	int F = -1;
	int x = -1;
	int y = -1;
	bool flag = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (table[i][j] == 0) {
				pair<int, int> info = findFR(i, j, I);
				int b = info.first;
				int f = info.second;
				if (f > F) {
					F = f;
					B = b;
					x = i;
					y = j;
					flag = 1;
				}
				else if (f == F) {
					if (b > B) {
						B = b;
						x = i;
						y = j;
						flag = 1;
					}
				}
			}
		}
	}
	if (flag == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (table[i][j] == 0) {
					x = i;
					y = j;
					break;
				}
			}
		}
	}
	table[x][y] = v[I][0].first;
}

pair<int, int> findFR(int x, int y, int idx) {
	int blank = 0;
	int FR = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			int ST = table[nx][ny];
			if (ST == 0) {
				blank++;
			}
			else {
				FR += find(ST, idx);
			}
		}
	}
	return { blank, FR };
}

int find(int ST, int idx) {
	for (int i = 0; i < v[idx].size(); i++) {
		if (ST == v[idx][i].second) {
			return 1;
		}
	}
	return 0;
}