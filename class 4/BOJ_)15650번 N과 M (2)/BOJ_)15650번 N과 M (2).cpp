/*BOJ_)15650¹ø N°ú M (2)
		b_d_o_o			*/
#include <iostream>
#include <vector>
using namespace std;
int N, M;
bool check[9] = { 0, };
vector<int> ans[1000];
void DFS(int cnt, int a);
int main() {
	cin >> N >> M;
	DFS(0, 1);
	return 0;
}
void DFS(int cnt, int a) {
	if (cnt == M) {
		for (int i = 0;i < 9;i++) {
			if (check[i] == 1) {
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
	for (int i = a; i <= N;i++) {
		check[i] = 1;
		DFS(cnt + 1, i + 1);
		check[i] = 0;
	}
}
