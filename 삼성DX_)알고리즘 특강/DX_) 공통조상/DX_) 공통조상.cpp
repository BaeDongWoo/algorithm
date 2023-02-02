#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> v[2];
int V, E, N, M;
int NM[2];
int cnt = 0;
struct Node {
	int data;
	Node* prev, * left, * right;
};
const int MAXN = 10001;
Node nodePool[MAXN];
void initNodePool() {
	for (int i = 1;i < MAXN;i++) {
		nodePool[i].data = 0;
		nodePool[i].prev = nullptr;
		nodePool[i].left = nullptr;
		nodePool[i].right = nullptr;
	}
}
void PRINT(Node* root, int i) {
	Node* p = root;
	while (p->prev != nullptr) {
		p = p->prev;
		int a = p->data;
		v[i].push_back(a);
	}
	return;
}
void search(Node* root, int target, int i) {
	if (root != nullptr) {
		if (root->data == target) {
			PRINT(root, i);
			return;
		}
		else {
			search(root->left, target, i);
			search(root->right, target, i);
			return;
		}
	}
}
void subTreeCnt(Node* root) {
	if (root != nullptr) {
		cnt++;
		subTreeCnt(root->left);
		subTreeCnt(root->right);
	}
}
void subTree(Node* root, int target) {
	if (root != nullptr) {
		if (root->data == target) {
			subTreeCnt(root);
			return;
		}
		else {
			subTree(root->left, target);
			subTree(root->right, target);
			return;
		}
	}
}

Node* getNode(int parents, int child) {
	nodePool[parents].data = parents;
	if (nodePool[parents].left == nullptr) {
		nodePool[parents].left = &nodePool[child];
		nodePool[parents].left->prev = &nodePool[parents];
		nodePool[parents].left->data = child;
	}
	else {
		nodePool[parents].right = &nodePool[child];
		nodePool[parents].right->prev = &nodePool[parents];
		nodePool[parents].right->data = child;
	}
	return &nodePool[parents];
}
int main() {
	int TC;
	cin >> TC;
	for (int testcase = 1;testcase <= TC;testcase++) {
		initNodePool();
		vector<int> vv;
		v[0].clear();
		v[1].clear();
		cnt = 0;
		cin >> V >> E >> NM[0] >> NM[1];
		for (int i = 0;i < E;i++) {
			int parents, child;
			cin >> parents >> child;
			getNode(parents, child);
		}
		for (int i = 0;i < 2;i++) {
			int target = NM[i];
			search(&nodePool[1], target, i);
		}

		for (int i = 0;i < v[0].size();i++) {
			for (int j = 0;j < v[1].size();j++) {
				if (v[0][i] == v[1][j]) {
					vv.push_back(v[0][i]);
					break;
				}
			}
		}
		subTree(&nodePool[1], vv[0]);
		cout << "#" << testcase << " ";
		cout << vv[0] << " " << cnt;
		cout << '\n';
	}
	return 0;
}