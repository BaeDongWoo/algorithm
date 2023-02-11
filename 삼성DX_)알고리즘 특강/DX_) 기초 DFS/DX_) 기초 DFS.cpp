/*DX_) ±‚√  DFS
	b_d_o_o		*/
using namespace std;
const int MAXN = 100;
bool check[MAXN];
bool flag = 0;
int arr[MAXN][5];
int arrCnt[MAXN];
void myDFS(int n, int k);
int result=-1;
void dfs_init(int N, int path[100][2])
{
	for (int i = 0;i < 100;i++) {
		arrCnt[i] = 0;
		for (int j = 0;j < 5;j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = 0;i < N-1 ;i++) {
		int parent = path[i][0];
		int child = path[i][1];
		int idx = arrCnt[parent];
		arr[parent][idx] = child;
		arrCnt[parent]++;
	}
}

int dfs(int n)
{
	flag = 0;
	int k = n;
	result = -1;
	myDFS(n, k);
	return result;
}

void myDFS(int n, int k) {
	int cnt = arrCnt[n];
	for (int i = 0;i < cnt;i++) {
		int nn = arr[n][i];
		if (nn > k) {
			if (flag == 0) {
				result = nn;
				flag = 1;
				return;
			}
		}
		myDFS(nn, k);
	}
	return;
}