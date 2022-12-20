/*BOJ_)1107번 리모컨
		b_d_o_o		*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	int N, M;
	vector <int> button;
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		int num;
		cin >> num;
		button.push_back(num);
	}
	int result = 9999999;
	int cnt = 0;
	string a;
	for (int i = 0;i <= 1000000;i++) {
		string I = to_string(i);
		bool check = 0;
		for (int j = 0;j < button.size();j++) {
			string B = to_string(button[j]);
			if (I.find(B) != string::npos) {
				check = 1;
				break;
			}
		}
		if (check == 0) {
			if (result > min(result, abs(N - i))) {
				result = min(result, abs(N - i));
				a = I;
			}
		}
	}
	while (result != 0) {
		if (result > 0) {
			result--;
			cnt++;
		}
		else {
			result++;
			cnt++;
		}
	}
	if (N == 100) {
		cnt = 0;
	}
	else {
		int result1 = cnt + a.size();
		int result2 = abs(N - 100);
		cnt = min(result1,result2);
	}
	cout << cnt;
	return 0;
}