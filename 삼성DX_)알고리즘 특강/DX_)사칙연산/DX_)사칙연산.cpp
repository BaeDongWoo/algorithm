/*DX_)사칙연산
	b_d_o_o	*/
#include <iostream>
#include <string>
using namespace std;
struct Node {
	string data;
	Node* left, * right;
};
const int MAXN = 1001;
Node nodePool[MAXN];

Node* getNode(int num,string data,Node *left,Node * right) {
	nodePool[num].data = data;
	nodePool[num].left = left;
	nodePool[num].right = right;
	return &nodePool[num];
}
float inOrder(Node* root) {	
	if (root->data[0] == '+') {
		return inOrder(root->left) + inOrder(root->right);
	}
	else if (root->data[0] == '-') {
		return inOrder(root->left) - inOrder(root->right);
	}
	else if (root->data[0] == '/') {
		return inOrder(root->left) / inOrder(root->right);
	}
	else if (root->data[0] == '*') {
		return inOrder(root->left) * inOrder(root->right);
	}
	else {
		return stof(root->data);
	}
}
int main() {
	int TC = 10;
	for (int testcase = 1;testcase <= TC;testcase++) {
		int N;
		cin >> N;
		for (int i = 0;i < N;i++) {
			int num;
			string data;
			int left, right;
			cin >> num;
			cin >> data;
			if (data[0]<'0') {
				cin >> left >> right;
				Node* newNode = getNode(num, data,&nodePool[left],&nodePool[right]);	
			}
			else {
				Node* newNode = getNode(num, data,nullptr,nullptr);
			}
		}
		int result = int(inOrder(&nodePool[1]));
		cout <<"#"<<testcase<<" "<<result<<'\n';
	}
	return 0;
}
