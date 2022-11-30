/*BOJ_) 1074¹ø Z
	b_d_o_o		*/
#include <iostream>
using namespace std;
int N, r, c;
int cnt;
void Z(int x, int y, int n);
int main(){
    cin >> N >> r >> c;
    Z(0, 0, (1 << N));
    return 0;
}
void Z(int x, int y, int n) {
    if (x == r && y == c) {
        cout << cnt << '\n';
        return;
    }
    if (r < x + n && r >= x && c < y + n && c >= y) {
        Z(x, y, n / 2);
        Z(x, y + n / 2, n / 2);
        Z(x + n / 2, y, n / 2);
        Z(x + n / 2, y + n / 2, n / 2);
    }
    else
    {
        cnt += n * n;
    }
}