/*BOJ_)1676�� ���丮�� 0!�� ����
		b_d_o_o				*/
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, cnt = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		if (i % 5 == 0) {
			cnt++;
		}
		if (i % 25 == 0) {
			cnt++;
		}
		if (i % 125 == 0) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}