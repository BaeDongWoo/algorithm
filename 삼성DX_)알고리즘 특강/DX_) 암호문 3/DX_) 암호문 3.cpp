/*DX_) ¾ÏÈ£¹® 3
	b_d_o_o	*/
#include <iostream>
#include <list>
using namespace std;
list<int> L;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int TC = 1;TC <= 10;TC++) {
		int N;
		int num;
		cin >> N;
		while(N--) {
			cin >> num;
			L.push_back(num);
		}
		int M;
		char C;
		cin >> M;
		while (M--) {
			int x, y, s;
			cin >> C;
			if (C == 'I') {				
				cin >> x >> y;
				list<int> S;
				list<int>::iterator it=L.begin();
				for (int i = 0;i < y;i++) {
					cin >> s;
					S.push_back(s);
				}
				for (int i = 0;i < x;i++) {
					it++;
				}
				L.splice(it, S);
			}
			else if (C == 'D') {
				cin >> x >> y;
				list<int>::iterator it = L.begin();
				for (int i = 0;i < x;i++) {
					it++;
				}
				for (int i = 0;i < y;i++) {
					it=L.erase(it);
				}
			}
			else if (C == 'A'){
				cin >> y;
				for (int i = 0;i < y;i++) {
					cin >> s;
					L.push_back(s);
				}
			}
		}
		cout << "#" << TC << " ";
		for (int i = 0;i < 10;i++) {
			cout << L.front()<<" ";
			L.pop_front();
		}
		cout << "\n";
		L.clear();
	}
	return 0;
}