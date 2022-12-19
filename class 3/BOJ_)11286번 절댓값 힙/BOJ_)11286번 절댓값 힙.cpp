/*BOJ_)11286�� ���� ��
		b_d_o_o			*/
#include <iostream>
#include<queue>
#include<functional>
#include<algorithm>
#include <utility>

using namespace std;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q; //greter ���� >> top�� ���� ������
int main() {
	int N; cin >> N;
	while (N--) {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		int X; cin >> X;
		if (X != 0) {//X���� 0�� �ƴϸ� X ���� Ǫ��
			q.push({ abs(X),X });
		}
		else {
			if (!q.empty()) {//X���� 0�̰� q�� ������� ������ 
				cout << q.top().second << '\n';//top>>���� ������
				q.pop();//top ����
			}
			else {
				cout << 0 << '\n';//��� �ִٸ� 0���
			}
		}
	}
	return 0;
}