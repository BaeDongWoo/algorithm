/*BOJ_)21736번 헌내기는 친구가 필요해 
			b_d_o_o			*/
#include <iostream>
#include <queue>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m;
string arr[600][600];
int visit[600][600];
int result;
pair <int, int> p;//도연이 좌표
void dfs(int X, int Y);
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			arr[i][j] = s[j];
			if (arr[i][j] == "I") {
				p.first = i;
				p.second = j;
			}
		}
	}
	dfs(p.first, p.second);
	if (result == 0) cout << "TT";
	else cout << result;
	return 0;
}
void dfs(int X, int Y) {
	visit[X][Y] = 1;
	queue <pair<int, int>> q;
	q.push(make_pair(X, Y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (visit[nx][ny] == 0 && arr[nx][ny] != "X") {
					visit[nx][ny] = 1;
					q.push(make_pair(nx, ny));
					if (arr[nx][ny] == "P") result++;
				}
			}
		}
	}
}