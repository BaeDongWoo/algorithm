/*BOJ_)1260锅 DFS客BFS
		b_d_o_o		*/
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include<algorithm>
using namespace std;
const int MAXN = 1001;
vector<int> dfs_bfs[MAXN];
vector<int> dfs_ans;
vector<int> bfs_ans;
bool vi_dfs[MAXN] = { 0, };
bool vi_bfs[MAXN] = { 0, };
void DFS(int a);
void BFS(int b);
int main() {
	int N, M, V;
	int n, m;
	cin >> N >> M >> V;
	while (M--) {
		cin >> n >> m;
		dfs_bfs[n].push_back(m);
		dfs_bfs[m].push_back(n);
	}
	DFS(V);
	BFS(V);
	for (int i = 0;i < dfs_ans.size();i++) {
		cout << dfs_ans[i] << ' ';
	}
	cout << '\n';
	for (int i = 0;i < bfs_ans.size();i++) {
		cout << bfs_ans[i] << ' ';
	}
}


void DFS(int a) {
	vi_dfs[a] = 1;//规巩贸府
	sort(dfs_bfs[a].begin(), dfs_bfs[a].end());
	dfs_ans.push_back(a);
	for (int i = 0;i < dfs_bfs[a].size();i++) {
		int vi = dfs_bfs[a][i];
		if (vi_dfs[vi] == 0) {
			vi_dfs[vi] = 1;
			DFS(vi);
		}
	}
	return;
}

void BFS(int b) {
	queue<int> bfs;
	bfs.push(b);
	vi_bfs[b] = 1;

	while (!bfs.empty()) {
		int vi = bfs.front();
		bfs.pop();
		bfs_ans.push_back(vi);
		for (int i = 0;i < dfs_bfs[vi].size();i++) {
			int c = dfs_bfs[vi][i];
			if (vi_bfs[c] == 0) {
				vi_bfs[c] = 1;
				bfs.push(c);
			}
		}
	}
}