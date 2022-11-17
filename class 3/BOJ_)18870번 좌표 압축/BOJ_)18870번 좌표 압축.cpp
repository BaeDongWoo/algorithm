/*BOJ_)18870번 좌표 압축
		b_d_o_o			*/

#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;

vector<int> arr;
vector<int> v;
int main() {
	int N;
	int X;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> X;
		arr.push_back(X);
		v.push_back(X);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(), v.end()), v.end());//중복제거
	for (int i = 0;i < N;i++) {
		int result = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
		cout << result<<' ';
	}
	return 0;
}