#define MAX_NODE 10000

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	nodeCnt = 0;
	if (head != nullptr) {
		head = nullptr;
	}
}

void addNode2Head(int data)
{
	Node* newNode = getNode(data);
	if (head != nullptr) {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	else {
		head = newNode;
	}
}

void addNode2Tail(int data)
{
	Node* p = head;
	Node* newNode = getNode(data);
	if (p == nullptr) {
		head = newNode;
	}
	else {
		while (p->next != nullptr) {
			p = p->next;
		}
		p->next = newNode;
		newNode->prev = p;
	}
}

void addNode2Num(int data, int num)
{
	if (nodeCnt + 1 < num)return;
	Node* p = head;
	Node* newNode = getNode(data);
	if (num == 1) {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	else {
		for (int i = 0; i < num - 2; i++) {
			if (p->next != nullptr) {
				p = p->next;
			}
		}
		if (p->next != nullptr) {
			newNode->next = p->next;
			newNode->prev = p;
			p->next->prev = newNode;
			p->next = newNode;
		}
		else {
			p->next = newNode;
			newNode->prev = p;
		}
	}
}

int findNode(int data)
{
	int cnt = 1;
	Node* p = head;
	while (p->data!=data) {
		p = p->next;
		cnt++;
	}
	return cnt;
}

void removeNode(int data)
{
	Node* p = head;
	if (p->data == data) {
		p = p->next;
		head = p;
	}
	else {
		while (p!=nullptr) {
			if(p->data==data){
				if (p->next != nullptr) {
					p->prev->next = p->next;
					p->next->prev = p->prev;
					break;
				}
				else {
					p->prev->next = nullptr;
					break;
				}
			}
			else {
				p = p->next;
			}
		}
	}
}


int getList(int output[MAX_NODE])
{
	Node* p = head;
	int cnt = 0;
	while (p != nullptr) {
		int a = p->data;
		output[cnt] = a;
		cnt++;
		p = p->next;
	}
	return cnt;
}

int getReversedList(int output[MAX_NODE])
{
	Node* p = head;
	int cnt = 0;
	while (p->next!= nullptr) {
		p = p->next;
	}
	while (p != nullptr) {
		int a = p->data;
		output[cnt] = a;
		cnt++;
		p = p->prev;
	}
	return cnt;
}