/*DX_) 수열편집
	b_d_o_o	*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
	int data;
	Node* next;
};
Node* head;
Node* getNode(int data) {
	Node* node = new Node;
	node->data = data;
	node->next = nullptr;
	return node;
}
void init() {
	head = nullptr;
}
void addNode(int data) {
	Node* newNode = getNode(data);
	if (head == nullptr) {
		head = newNode;
	}
	else {
		Node* p = head;
		while (p->next != nullptr) {
			p = p->next;
		}
		p->next = newNode;
	}
}
void addNodeNum(int idx, int data) {
	Node* p = head;
	Node* newNode = getNode(data);
	for (int i = 1;i < idx;i++) {
		p = p->next;
		if (p == nullptr) {
			return;
		}
	}
	if (p->next != nullptr) {
		newNode->next = p->next;
		p->next = newNode;
	}
	else {
		p->next = newNode;
	}
}
void deleteNode(int idx) {
	Node* p = head;
	for (int i = 1;i < idx;i++) {
		p = p->next;
		if (p == nullptr) {
			return;
		}
	}
	if (p->next != nullptr) {
		if (p->next->next != nullptr) {
			p->next = p->next->next;
		}
		else {
			p->next = nullptr;
		}
	}
}
void ChangeNode(int idx, int data) {
	Node* p = head;
	Node* newNode = getNode(data);
	for (int i = 1;i < idx;i++) {
		p = p->next;
		if (p == nullptr) {
			return;
		}
	}
	if (p->next != nullptr) {
		if (p->next->next != nullptr) {
			newNode->next = p->next->next;
			p->next = newNode;
		}
		else {
			p->next = newNode;
		}
	}
}
int idxNodePrint(int idx) {
	Node* p = head;
	for (int i = 0;i < idx;i++) {
		p = p->next;
		if (p == nullptr) {
			return -1;
		}
	}
	return p->data;
}
int main() {
	int TC;
	cin >> TC;
	for (int T = 1;T <= TC;T++) {
		int N, M, L;
		init();
		cin >> N >> M >> L;
		for (int i = 0;i < N;i++) {
			int a;
			cin >> a;
			addNode(a);
		}
		for (int i = 0;i < M;i++) {
			char command;
			cin >> command;
			if (command == 'I') {
				int num, idx;
				cin >> idx >> num;
				addNodeNum(idx , num);
			}
			else if (command == 'D') {
				int idx;
				cin >> idx;
				deleteNode(idx);
			}
			else if (command == 'C') {
				int idx, num;
				cin >> idx >> num;
				ChangeNode(idx,num);
			}
		}
		int result=idxNodePrint(L);
		cout << "#" << T << " " << result << '\n';
	}
	return 0;
}