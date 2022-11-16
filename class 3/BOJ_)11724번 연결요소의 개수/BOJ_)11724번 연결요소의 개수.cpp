/*BOJ_)11724�� �������� ����
			b_d_o_o			*/
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
const int MAXN = 1000;
vector<int>v[MAXN];
bool check[MAXN] = { 0, };
void conect(int a);

int main() {
	int N, M;
	int U, V;
	int cnt = 0;
	cin >> N >> M;
	for (int i = 0;i < M;i++) {//��������
		cin >> U >> V;
		v[U].push_back(V);
		v[V].push_back(U);
	}
	for (int i = 1;i <= N;i++) {
		if (check[i] == 0) {
			cnt++;
			conect(i);
		}
	}
	cout << cnt;
	return 0;
}

void conect(int a) {
	if (check[a] == 0) {
		check[a] = 1;//�湮ó��
	}
	for (int i = 0;i < v[a].size();i++) {
		int b = v[a][i];
		if (check[b] == 0) {
			conect(b);
		}
	}
}