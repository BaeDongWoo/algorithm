/*BOJ_)16928번 뱀과 사다리 게임
			b_d_o_o			*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MINN = 1;
const int MAXN = 100;
int player = MINN;
int finish = MAXN;
int num = 0;
vector<int> ladderOrSnake[MAXN];
bool check[MAXN]={0, };
void game(int idx, int cnt);
int main() {
	int N, M;
	cin >> N >> M;
	while (N--) {
		int x, y;
		cin >> x >> y;
		ladderOrSnake[x].push_back(y);
	}
	while (M--) {
		int u, v;
		cin >> u >> v;
		ladderOrSnake[u].push_back(v);
	}
	game(player,num);
	return 0;
}
void game(int idx,int cnt) {
	
	queue<pair<int, int>> q;
	q.push(make_pair(idx, cnt));
	while (!q.empty()) {
		int x = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 1;i < 7;i++) {
			int newx = x + i;
			if (newx == MAXN) {
				cout << c + 1;
				return;
			}
			else if(newx<100) {
				while(!ladderOrSnake[newx].empty()) {
					newx = ladderOrSnake[newx][0];
				}
				if (check[newx] == 0) {
					q.push(make_pair(newx, c + 1));
					check[newx] = 1;
				}
				
			}
		}
	}
}