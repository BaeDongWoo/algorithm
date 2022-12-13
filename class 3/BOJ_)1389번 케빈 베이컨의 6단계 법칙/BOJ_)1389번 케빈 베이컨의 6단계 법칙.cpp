/*BOJ_)1389번 케빈 베이컨의 6단계 법칙
			b_d_o_o					*/
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> FR[101];
int sum = 0;
bool visit[101] = { 0, };
int N, M;
int cnt = 0;
pair<int, int>result[100];
int BFS(int start, int target);
int main() {
	int a, b;
	int ans=0;
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		cin >> a >> b;
		FR[a].push_back(b);
		FR[b].push_back(a);
	}
	for (int i = 1;i <= N;i++) {
		sum = 0;
		for (int j = 1;j <=N;j++) {
			cnt = 0;
			if (i != j) {
				fill_n(visit, 101, 0);
				cnt=BFS(i,j);
				sum += cnt;
			}
		}
		result[i].first = sum;
		result[i].second = i;
	}
	sort(result, result + N + 1);
	cout << result[1].second;
	return 0;
}
int BFS(int start,int target) {
	queue<pair<int,int>> q;
	q.push(make_pair(start,0));
	visit[start] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		cnt = q.front().second;
		q.pop();
		if (x == target) {
			return cnt;
		}
		for (int i = 0;i < FR[x].size();i++) {
			if (visit[FR[x][i]] == 0) {
				q.push(make_pair(FR[x][i],cnt+1));
				visit[FR[x][i]] = 1;
			}
		}
	}
}