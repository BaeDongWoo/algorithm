/*DX_) ���Ƹ��� �����ϱ�
		b_d_o_o		*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
long long arr[10000][16] = { 0, };
int main() {
	int T;
	cin >> T;
	for (int i = 1;i <= T;i++) {
		string people;
		memset(arr, 0,sizeof(arr));
		cin >> people;
		for (int j = 0;j < people.size();j++) {// ��¥
			int manager = 1 << (people[j] - 'A');
			for (int k = 1;k <= 15;k++) {//����� ��
				if (j == 0) {
					if ((k & manager) != 0 && (k & 1) != 0) {//A���� å���ڸ�� ���� �ɶ� ����� �� ī��Ʈ
						arr[j][k] = 1;
					}
				}
				else {
					if (arr[j - 1][k] != 0) {
						for (int l = 1;l <= 15;l++) {
							if ((l & manager) != 0 && (k & l) != 0) {
								arr[j][l] += arr[j - 1][k];
								arr[j][l] %= 1000000007;
							}
						}
					}
				}
			}
		}
		long long result = 0;
		for (int j = 1;j <= 15;j++) {
			result += arr[people.size() - 1][j];
			result %= 1000000007;
		}
		cout << "#" << i << ' ' << result << '\n';
	}
	return 0;
}
