/*BOJ_)9375번 패션왕 신해빈
		b_d_o_o			*/
#include <iostream>
#include<map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v;
map<string, int> m;
string a, b;
int main() {
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		v.clear();
		m.clear();
		while (N--) {
			cin >> a >> b;
			m[b]++;//같은 종류의 옷이 들어올때 마다 value값을 하나씩 카운트
			v.push_back(b);//벡터에 옷의 종류를 넣음
		}
		int ans = 1;
		sort(v.begin(), v.end());//정렬
		v.erase(unique(v.begin(), v.end()), v.end());//중복제거
		for (int i = 0;i < v.size();i++) {
			ans = ans * (m[v[i]]+1);//map에 저장된 value값에 +1한뒤 곱함
		}							
		cout << ans - 1<<'\n';//전부다 입지않는 경우의수 1을 빼줌
	}
	return 0;

}




