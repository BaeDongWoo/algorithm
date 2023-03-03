/*BOJ_)20055번 컨베이어 벨트 위의 로봇
				b_d_o_o				*/
#include <iostream>
using namespace std;
int N, K;
int railHP[202];
int robotIdx[202];
int result;
void rail();
void robotMove();
void newRobot();
void searchRailHP();
void robotDown();
bool flag = 1;
int main() {
    cin >> N >> K;
    for (int i = 0; i < N * 2; i++) {
        int A;
        cin >> A;
        railHP[i] = A;
    }
    while (flag) {
        result++;
        rail();
        robotMove();
        newRobot();
        searchRailHP();
    }
    cout << result;
    return 0;
}

void rail() {// 레일을 한칸씩 이동
    int Ai = railHP[0];
    int nAi;
    int Ri = robotIdx[0];
    int nRi;
    for (int i = 0; i < N * 2; i++) {
        
        if (i + 1 == N * 2) {
            nAi = railHP[0];
            railHP[0] = Ai;
            nRi = robotIdx[0];
            robotIdx[0] = Ri;

        }
        else {
            nAi = railHP[i + 1];
            railHP[i + 1] = Ai;
            nRi = robotIdx[i + 1];
            robotIdx[i + 1] = Ri;
        }
        Ai = nAi;
        Ri = nRi;
    }
    robotDown();
}

void robotDown() {
    robotIdx[N - 1] = 0;
}
void robotMove() {
    for (int i = N;i > 0;i--) {
        if (robotIdx[i] == 1) {
            int ni = i + 1;          
            if (robotIdx[ni] == 0 && railHP[ni] != 0) {
                robotIdx[i] = 0;
                robotIdx[ni] = 1;
                railHP[ni]--;
                i = ni;               
            }
        }
    }
    robotDown();
}

void newRobot() {
    if (robotIdx[0] == 0 && railHP[0] != 0) {
        robotIdx[0] = 1;
        railHP[0]--;
    }
}

void searchRailHP() {
    int cnt = 0;
    for (int i = 0; i < N * 2; i++) {
        if (railHP[i] == 0) {
            cnt++;
        }
    }
    if (cnt >= K) {
        flag = 0;
    }
}