/*DX_) ÇÏ³ª·Î
	b_d_o_o	*/
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
typedef long long ll;
const int MAXN = 1001;
using namespace std;
pair<ll, ll> point[MAXN];
int parent[MAXN];
ll ans;
vector < pair < ll, pair < ll, ll>>> v;
double E;
ll calc(int i, int j);
void setParents(int N);
void solve();
bool checkParent(int a, int b);
int find(int a);
void uni(int a, int b);
int cnt = 0;
void init() {
	ans = 0;
	v.clear();
	memset(point, 0, sizeof(point));
	memset(parent, 0, sizeof(parent));
	E = 0.0;
}
int main() {
	int TC;
	cin >> TC;
	for (int testcase = 1;testcase <= TC;testcase++) {
		int N;
		init();
		cin >> N;
		for (int i =1;i <= N;i++) {
			cin >> point[i].first;
		}
		for (int i = 1;i <= N;i++) {
			cin >> point[i].second;
		}
		cin >> E;
		for (int i = 1;i <= N;i++) {
			for (int j = i + 1;j <= N;j++) {
				ll pay = calc(i, j);
				v.push_back(make_pair(pay, make_pair(i, j)));
			}
		}
		sort(v.begin(), v.end());
		setParents(N);
		solve();
		cout << fixed;
		cout.precision(0);
		cout << "#" << testcase << " " << (double)(ans * E) << '\n';
	}
	return 0;
}

ll calc(int i, int j) {
	ll dx = (point[i].first - point[j].first) * (point[i].first - point[j].first);
	ll dy = (point[i].second - point[j].second) * (point[i].second - point[j].second);
	return dx + dy;
}
void setParents(int N) {
	for (int i = 1;i <= N;i++) {
		parent[i] = i;
	}
}
void solve() {
	for (int i = 0;i < v.size();i++) {
		int a = v[i].second.first;
		int b = v[i].second.second;
		if (checkParent(a, b) == false) {
			if (find(a) != find(b)) {
				parent[find(b)] = find(a);
			}
			ans = ans + v[i].first;
		}
	}
}
bool checkParent(int a, int b) {
	int A = find(a);
	int B = find(b);
	if (A != B) return false;
	else return true;
}
int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	else {
		return parent[a]=find(parent[a]);
	}
}
