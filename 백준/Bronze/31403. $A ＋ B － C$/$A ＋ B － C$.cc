
/*BOJ_)31403번 A+B-C */
#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int strSolve = stoi(to_string(a) + to_string(b)) - c;
	cout << a+b-c << '\n' << strSolve;
}