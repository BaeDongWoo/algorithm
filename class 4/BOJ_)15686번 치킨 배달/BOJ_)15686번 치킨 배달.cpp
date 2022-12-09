/*BOJ_)15686번 치킨 배달
		b_d_o_o			*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
const int MAXN = 99999999;
vector<pair<int, int>> house;
vector<pair<int, int>> chickenHouse;
int minResult = MAXN;
void DFS(int cnt,int a);
void chickenRoad();
bool check[13] = { 0, };
int N, M;
int cnt = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int info;
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			cin >> info;
			if (info == 1) {
				house.push_back(make_pair(j, i));
			}
			if (info == 2) {
				chickenHouse.push_back(make_pair(j, i));
			}
		}
	}
	DFS(0,0);
	cout << minResult;
}

void DFS(int cnt,int a) {
	if (cnt == M) {
		chickenRoad();
		return;
	}
	for (int i = a;i < chickenHouse.size();i++) {
		if (check[i] == 1) {
			continue;
		}
		check[i] = 1;
		DFS(cnt + 1,i);
		check[i] = 0;	
	}
}

void chickenRoad() {
	int resultRoad = 0;
	for (int i = 0;i < house.size();i++) {
		int x = house[i].first;
		int y = house[i].second;
		int Min = MAXN;
		int comp = 0;
		for (int j = 0;j < chickenHouse.size();j++) {
			if (check[j] == 1) {
				int cx = chickenHouse[j].first;
				int cy = chickenHouse[j].second;
				comp=abs(x - cx) + abs(y - cy);
				Min = min(Min, comp);
			}
		}
		resultRoad += Min;
	}
	minResult = min(minResult, resultRoad);
	return;
}
