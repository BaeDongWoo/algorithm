#include<iostream>
using namespace std;
struct Node {
	int num;
	char alpa;
	Node *left, *right;
};
Node nodePool[100];
int nodeCnt = 0;
Node* getNode(int num,char data) {
	nodePool[nodeCnt].num = num;
	nodePool[nodeCnt].alpa = data;
	nodePool[nodeCnt].left = nullptr;
	nodePool[nodeCnt].right = nullptr;
	return &nodePool[nodeCnt++];
}

void inorder(Node* root) {
	if (root != nullptr) {
		inorder(root->left);
		cout << root->alpa;
		inorder(root->right);
	}
}
int main() {
	for (int TC = 1;TC <= 10;TC++) {
		nodeCnt = 0;
		int N;
		cin >> N;
		for (int i = 0;i < N;i++) {
			int num;
			cin >> num;
			if (N % 2 == 0) {//NÀÌ Â¦¼öÀÏ¶§
				if (N / 2 > num) {
					char alpa;
					int l, r;
					cin >> alpa >> l >> r;
					Node* newNode = getNode(num, alpa);
					newNode->left = &nodePool[l - 1];
					newNode->right = &nodePool[r - 1];
				}
				else if (N / 2 < num) {
					char alpa;
					cin >> alpa;
					Node* newNode = getNode(num, alpa);
					newNode->left = nullptr;
					newNode->right = nullptr;
				}
				else if (N / 2 == num) {
					int l;
					char alpa;
					cin >> alpa >> l;
					Node* newNode = getNode(num, alpa);
					newNode->left = &nodePool[l-1];
					newNode->right = nullptr;
				}
			}
			else {//NÀÌ È¦¼ö ÀÏ¶§
				if (N / 2 >= num) {
					char alpa;
					int l, r;
					cin >> alpa >> l >> r;
					Node* newNode = getNode(num, alpa);
					newNode->left = &nodePool[l - 1];
					newNode->right = &nodePool[r - 1];
				}
				else if (N / 2 < num) {
					char alpa;
					cin >> alpa;
					Node* newNode = getNode(num, alpa);
					newNode->left = nullptr;
					newNode->right = nullptr;
				}
			}
		}
		cout << "#" << TC << ' ';
		inorder(&nodePool[0]);
		cout << '\n';
	}
}