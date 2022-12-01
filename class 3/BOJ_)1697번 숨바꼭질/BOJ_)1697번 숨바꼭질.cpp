/*BOJ_)1697번 숨바꼭질
		b_d_o_o		*/
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
const int MAXN = 100001;
queue<pair<int,int>> idx;
bool visit[MAXN]={0, };
int N, K;
void bfs(int n);
int main() {
	cin >> N >> K;
	visit[N] = 1;
	bfs(N);
}

void bfs(int n) {
	int time = 0;
	idx.push(make_pair(n, time));
	while (!idx.empty()) {
		n = idx.front().first;
		time = idx.front().second;
		idx.pop();
		if (n - 1 >= 0) {
			if (visit[n - 1] == 0) {
				visit[n - 1] = 1;
				idx.push(make_pair(n - 1, time+1));
			}
		}
		if (n + 1 <= MAXN) {
			if (visit[n + 1] == 0) {
				visit[n + 1] = 1;
				idx.push(make_pair(n + 1, time+1));
			}
		}
		if (2 * n <= MAXN) {
			if (visit[2 * n] == 0) {
				visit[2 * n] = 1;
				idx.push(make_pair(2 * n, time+1));
			}
		}
		if (n == K) {
			cout << time;
			break;
		}
	}
}