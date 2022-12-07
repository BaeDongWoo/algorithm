/*BOJ_)1541น๘ ภาพ๎น๖ธฐ ฐýศฃ
		b_d_o_o			*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	string number;
	int p_number=0;
	int m_number=0;
	int result = 0;
	bool minuscheck=0;
	cin >> input;
	for (int i = 0;i < input.size();i++) {
		if (input[i] != '+' && input[i] != '-') {
			number += input[i];
		}
		if(input[i]=='-') {
			if (minuscheck == 1) {
				m_number -= stoi(number);
				number = "";
			}
			else {
				p_number += stoi(number);
				number = "";
			}
		}
		if (input[i] == '+') {
			if (minuscheck == 1) {
				m_number -= stoi(number);
				number = "";
			}
			else {
				p_number += stoi(number);
				number = "";
			}
		}
		if (i == input.size()-1) {
			if (minuscheck == 1) {
				m_number -= stoi(number);
				number = "";
			}
			else {
				p_number += stoi(number);
				number = "";
			}
		}
		if (input[i] == '-') {
			minuscheck = 1;
		}
	}
	result = p_number + m_number;
	cout << result;
	return 0;
}

