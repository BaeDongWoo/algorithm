/*BOJ_) N°úM (8)
	b_d_o_o		*/
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 8;
int N, M;
int arr[MAX];
int visited[MAX];
void DFS(int idx, int start, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[visited[i]] << " ";
		}
		cout << "\n";
		return;
	}
	if (idx == N)
	{
		return;
	}
	for (int i = start; i < N; i++)
	{
		visited[idx] = i;
		DFS(idx + 1, i, cnt + 1);
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	DFS(0, 0, 0);
	return 0;
}