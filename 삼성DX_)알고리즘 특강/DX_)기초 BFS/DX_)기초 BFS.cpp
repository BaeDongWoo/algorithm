/*DX_)±‚√  BFS*/

using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int Map[11][11];
int front, rear;
void bfs_init(int map_size, int map[10][10]) {
    for (int i = 1;i <= map_size;i++) {
        for (int j = 1;j <= map_size;j++) {
            Map[i][j] = map[i-1][j-1];
        }
    }
}
int bfs(int x1, int y1, int x2, int y2) {
    front = rear = 0;
    int score[11][11];
    for (int i = 0;i < 11;i++) {
        for (int j = 0;j < 11;j++) {
            score[i][j] = -1;
        }
    }
    int queue[102][2] = { {0,}, };
    int result = -1;
    queue[rear][0] = y1;
    queue[rear][1] = x1;
    score[y1][x1] = 0;
    rear++;
    while (front != rear) {
        int x = queue[front][0];
        int y = queue[front][1];
        int s = score[x][y];
        front++;
        if (x == y2 && y == x2) {
            result = s;
            return result;
        }
        if (Map[x][y]==0) {
            for (int i = 0;i < 4;i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 1 && ny >= 1 && nx <= 10 && ny <= 10) {
                    if (score[nx][ny] == -1 && Map[nx][ny] == 0) {
                        queue[rear][0] = nx;
                        queue[rear][1] = ny;
                        score[nx][ny] = s + 1;
                        rear++;
                    }
                }
            }
        }
    }
    return result;
}