/*DX_)��Ģ���� ��ȿ�� �˻�
		b_d_o_o		*/
#include <iostream>

using namespace std;

int main() {
	int TC = 10;
	for (int T = 1;T <= TC;T++) {
		int N;
		int result = 1;
		cin >> N;
		for (int i = 0;i < N;i++) {
			int num;
			cin >> num;
			if (N % 2 == 0) {
				if (N / 2 > num) {
					char data;//data�� ��ȣ
					int l, r;
					cin >> data >> l >> r;
					if (data >= '0') {
						result = 0;
					}
				}
				else if (N / 2 < num) {
					char data;//data�� ����
					cin >> data;
					if (data < '0') {
						result = 0;
					}
				}
				else if (N / 2 == num) {
					char data;//data�� ����
					int l;
					cin >> data >> l;
					if (data < '0') {
						result = 0;
					}
				}
			}
			else {
				if (N / 2 >= num) {
					char data;//data�� ��ȣ
					int l, r;
					cin >> data >> l >> r;
					if (data >= '0') {
						result = 0;
					}
				}
				else {
					char data;//data�� ����
					cin >> data;
					if (data < '0') {
						result = 0;
					}
				}
			}
		}
		cout << "#" << T << ' ' << result<<'\n';
	}
	return 0;
}