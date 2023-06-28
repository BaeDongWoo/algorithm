/*BOJ_)20529번 가장 가까운 세 사람의 심리적 거리
				b_d_o_o				*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
//0~15
//ISTJ, ISFJ, INFJ, INTJ, ISTP, ISFP, INFP, INTP, ESTP, ESFP, ENFP, ENTP, ESTJ, ESFJ, ENFJ, ENTJ
int score[16][16];
vector <string> v;
map <string, int> m;
string mbti[16] = { "ISTJ", "ISFJ", "INFJ","INTJ", "ISTP", "ISFP", "INFP", "INTP", "ESTP", "ESFP", "ENFP", "ENTP", "ESTJ", "ESFJ", "ENFJ", "ENTJ" };
int n;
int result = 987654321;
string arr[100000];
void run();
void combi(int idx, int cnt);
vector <int> vv;
int main() {
	for (int i = 0; i < 16; i++) {//각 mbti별 비교 점수를 테이블에 담기
		for (int j = 0; j < 16; j++) {
			string s = mbti[i];
			string ss = mbti[j];
			int temp = 0;
			if (s != ss) {
				for (int k = 0; k < 4; k++) {
					if (s[k] != ss[k]) temp++;
				}
			}
			score[i][j] = temp;
		}
	}
	for (int i = 0; i < 16; i++) m[mbti[i]] = i;

	int T;
	cin >> T;
	while (T--) {
		result = 987654321;
		cin >> n;
		if (n > 32) {
			for (int i = 0; i < n; i++) {
				cin >> arr[i];
			}
			cout << 0 << '\n';
		}
		else {
			for (int i = 0; i < n; i++) {
				cin >> arr[i];
			}
			combi(0, 0);
			cout << result << '\n';
		}
	}
	for (int i = 0; i < vv.size(); i++) cout << vv[i] << "\n";
	return 0;
}
//n=4
// 0 1 2 
// 0 1 3
// 0 2 3
void combi(int idx, int cnt) {
	if (cnt == 3) {
		run();
		return;
	}
	for (int i = idx; i < n; i++) {
		v.push_back(arr[i]);
		combi(i + 1, cnt + 1);
		v.pop_back();
	}
}
void run() {
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			int idx = m[v[i]];
			int idxx = m[v[j]];
			sum += score[idx][idxx];
		}
	}
	if (result > sum) result = sum;
}