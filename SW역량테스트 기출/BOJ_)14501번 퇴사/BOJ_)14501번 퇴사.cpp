/*BOJ_)14501번 퇴사
		b_d_o_o		*/
#include <iostream>
#include<vector>
#include<utility>
using namespace std;
vector<pair<int, int>> v[15];
int N;
int T, P;
int result;
void consul(int day,int a);
int main() {
	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> T >> P;
		v[i].push_back(make_pair(T, P));
	}
	for (int i = 1;i <= N;i++) {
		consul(i,0);
	}
	cout << result;
	return 0;
}

void consul(int day,int a) {
	int pay = a;	
	int endConsul = day + v[day][0].first - 1;//상담 마지막 날
	if (endConsul <= N) {
		int nextConsul = endConsul + 1;
		pay += v[day][0].second;
		for (int i = nextConsul;i <= N;i++) {
			int nextEndConsul = i + v[i][0].first-1;
			if (nextEndConsul <= N) {
				consul(i,pay);
			}
		}
	}
	result = max(result, pay);
}