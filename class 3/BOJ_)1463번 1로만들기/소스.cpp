/*BOJ_) 1463�� 1�� �����		
		b_d_o_o			*/
#include <iostream>
using namespace std;
int x;
const int MAXN = 10000001;
int arr[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> x;
	arr[1] = 0;
	arr[2] = 1;
	for (int i = 3;i <= x;i++) {
		arr[i] = arr[i - 1]+1;//�������� -1�� �ϴ� ����� �ּҰ�
		if (i%3==0) {
			arr[i] = min(arr[i], arr[i / 3] + 1);//-1�ϴ� ����� �ּҰ��� ���� 3���� �������� ���� +1�� ���� ��
		}										
		if (i % 2==0) {
			arr[i] = min(arr[i] , arr[i / 2] + 1);//-1�ϴ� ����� �ּҰ��� ���� 2���� �������� ���� +1�� ���� ��
		}
	}
	cout << arr[x] << '\n';
	return 0;
}