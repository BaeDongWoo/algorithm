/*BOJ_)9375�� �мǿ� ���غ�
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
			m[b]++;//���� ������ ���� ���ö� ���� value���� �ϳ��� ī��Ʈ
			v.push_back(b);//���Ϳ� ���� ������ ����
		}
		int ans = 1;
		sort(v.begin(), v.end());//����
		v.erase(unique(v.begin(), v.end()), v.end());//�ߺ�����
		for (int i = 0;i < v.size();i++) {
			ans = ans * (m[v[i]]+1);//map�� ����� value���� +1�ѵ� ����
		}							
		cout << ans - 1<<'\n';//���δ� �����ʴ� ����Ǽ� 1�� ����
	}
	return 0;

}




