/*BOJ_)11725번 트리의 부모찾기
			b_d_o_o			*/
#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 100001;
int N;
int arr[MAXN];
bool visited[MAXN];
vector<int> v[MAXN];
void dfs(int a) {
    visited[a] = true;
    for (int i = 0;i < v[a].size();i++) {
        int next = v[a][i];
        if (!visited[next]) {
            arr[next] = a;
            dfs(next);
        }
    }
}
int main() {
    cin >> N;
    for (int i = 0;i < N-1;i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    for (int i = 2;i <= N;i++) cout << arr[i] << "\n";
}