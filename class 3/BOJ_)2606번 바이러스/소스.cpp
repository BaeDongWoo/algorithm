/*BOJ_)2606번 바이러스
		b_d_o_o		*/
#include <iostream>
#include <vector>
using namespace std;

bool vi[101] = { 0, };
vector<int> v[101];
int dfs(int a);
int cnt = 0;
int main() {
	int N, M;
	int n, m;
	cin >> N >> M;

	for (int i = 0;i < M;i++) {
		cin >> n >> m;
		v[n].push_back(m);
		v[m].push_back(n);
	}
	dfs(1);
	cout << cnt;
}

int dfs(int a) {
	vi[a] = 1;//방문처리
	for (int i = 0;i < v[a].size();i++) {
		int b = v[a][i];
		if (vi[b] == 0) {//방문x
			vi[b] = 1;
			cnt++;
			dfs(b);
		}
	}
	return cnt;
}