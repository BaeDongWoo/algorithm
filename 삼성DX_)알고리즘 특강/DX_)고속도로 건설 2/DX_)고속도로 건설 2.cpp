/*DX_)고속도로 건설 2
		b_d_o_o		*/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
vector<pair<int, pair<int, int>>> v;
int parent[50001];
long long pay = 0;
void parentSet(int n);
void solve();
bool checkParent(int a, int b);
int find(int a);
void init() {
	v.clear();
	pay = 0;
	memset(parent, 0, sizeof(parent));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int testcase = 1;testcase <= T;testcase++) {
		int N;
		int M;
		int S, E, C;
		init();
		cin >> N >> M;
		for (int i = 0;i <M;i++) {
			cin >> S >> E >> C;
			v.push_back(make_pair(C, make_pair(S, E)));
		}
		sort(v.begin(), v.end());
		parentSet(N);
		solve();
		cout << "#" << testcase << " " << pay<<'\n';
	}
	return 0;
}

void parentSet(int n) {
	for (int i = 0;i < n;i++) {
		parent[i] = i;
	}
}
void solve() {
	for (int i = 0;i < v.size();i++) {
		int a = v[i].second.first;
		int b = v[i].second.second;
		if (checkParent(a, b) == false) {
			int A = find(a);
			int B = find(b);
			if (A != B) {
				parent[B] = A;
			}
			pay += v[i].first;
		}
	}
}
bool checkParent(int a, int b) {
	int A = find(a);
	int B = find(b);
	if (A != B) {
		return false;
	}
	else return true;
}

int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	else {
		return parent[a] = find(parent[a]);
	}
}