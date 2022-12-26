/*BOJ_)5430번 AC
	b_d_o_o		*/
#include<iostream>
#include<string>
#include<deque>
using namespace std;
deque <string> num;
int main() {
	int T, N;
	string P;
	string arr;
	cin >> T;

	while (T--) {
		cin >> P >> N >> arr;
		for (int i = 0;i < arr.size();i++) {
			if (arr[i] == 91 || arr[i] == 44) {
				string a;
				for (int j = i+1;j < arr.size();j++) {
					if (arr[j] != 91 && arr[j] != 44&&arr[j]!=93) {
						a += arr[j];
					}
					else {
						i = j-1;
						break;
					}
				}
				if (a != "") {
					num.push_back(a);
				}
			}
		}
		bool check = 0;// 뒤집어진 상태 확인
		bool error = 0;
		for (int i = 0;i < P.size();i++) {
			if (!num.empty()) {
				if (P[i] == 68) {
					if (check == 0) {
						num.pop_front();
					}
					else {
						num.pop_back();
					}
				}
				else {
					if (check == 0) {
						check = 1;
					}
					else {
						check = 0;
					}
				}
			}
			else {
				if (P[i] == 68) {
					error = 1;
					cout << "error" << '\n';
					break;
				}
			}
		}
		if (!num.empty()) {
			cout << "[";
			if (check == 0) {
				while (!num.empty()) {
					cout << num.front();
					num.pop_front();
					if (!num.empty()) {
						cout << ",";
					}
				}
			}
			else{
				while (!num.empty()) {
					cout << num.back();
					num.pop_back();
					if (!num.empty()) {
						cout << ",";
					}
				}
			}
			cout << "]"<<"\n";
		}
		else {
			if (error == 0) {
				cout << "[" << "]" << "\n";
			}
		}
	}
	return 0;
}
