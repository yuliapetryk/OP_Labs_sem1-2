#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int dat;
	Node* next;
	Node* prev;
};

Node* first(int);
void add(Node**, int);
int findnumber(Node* const, int);
Node* find(Node* const, int);
bool remove(Node**, Node**, int);
Node* insert(Node* const, Node**, int, int);
void lprint(Node*);
void ldel(Node*);
queue <int> addqueue( int, queue <int>,Node*);
void view(queue <int>);

int main() {
	int n, k, m, number;
	cout <<"Enter the number of items  ";
	cin >> n;
	Node* pbeg = first(1); 
	Node* pend = pbeg;    
	Node* p;
	for (int i = 2; i <= n; i++) add(&pend, i);
	lprint(pbeg);
	cout << "Enter the item to insert = ";
	cin >> k;
	cout << "After  ";
	cin >> m;
	p = insert(pbeg, &pend, m, k);
	lprint(pbeg);
	cout <<"Enter the item to delete  ";
	cin >> k;
	if (!remove(&pbeg, &pend, k)) cout << "no find " << endl;
	lprint(pbeg);  
	cout << "Item= ";
	cin >> k;
	cout << "Number of this item " << findnumber(pbeg, k) << endl;


	queue <int> q;
	q= addqueue( n, q,pbeg);
	cout << "Enter the item to insert = ";
	cin >> k;
	q.push(k);
	cout << "Program will delete the first item  " << endl;
	q.pop();
	cout << "The queue: ";
	view(q);
	size_t l;
	l = q.size();
	cout << "The queue length is " << l << "." << endl;
	ldel(pbeg);  
	system("pause");
	return 0;
}
queue <int> addqueue( int n, queue <int> q, Node* pbeg) {
	Node* pv = pbeg;
	for (int h = 0; h < n; h++) {
		q.push(pv->dat);
	pv = pv->next;			  
		   
	}
	return q;
}

void view(queue <int> q) {
	while (!q.empty())
	{
		int val = q.front();
		q.pop();
		cout << val << " ";
	}
	cout << endl;
}
   
Node* first(int d) {
	Node* pv = new Node;
	pv->dat = d; pv->next = NULL; pv->prev = NULL;
	return pv;
}

void add(Node** pend, int d) {
	Node* pv = new Node;
	pv->dat = d; pv->next = NULL; pv->prev = *pend;
	(*pend)->next = pv;
	*pend = pv;
}


int findnumber(Node *const pbeg, int d) {
	Node *pv = pbeg;
	int number=1;
	while (pv) {
		if (pv->dat == d) break;
		else {
			pv = pv->next;
			number = number + 1;
		}
	}
	return (number);
}

Node *find(Node *const pbeg, int d) {
	Node *pv = pbeg;
	while (pv) {
		if (pv->dat == d) break;
		pv = pv->next;
	 
	}
	return pv;
}

bool remove(Node** pbeg, Node** pend, int k) {
	if (Node* pkey = find(*pbeg, k)) {
		if (pkey == *pbeg) {
			*pbeg = (*pbeg)->next;
			(*pbeg)->prev = NULL;
		}
		else if (pkey == *pend) {
			*pend = (*pend)->prev;
			(*pend)->next = NULL;
		}
		else {
			(pkey->prev)->next = pkey->next;
			(pkey->next)->prev = pkey->prev;
		}
		delete pkey;
		return true;
	}
	return false;
}


Node* insert(Node* const pbeg, Node** pend, int k, int m) {
	if (Node* pkey = find(pbeg,k) ){
		Node* pv = new Node;
		pv->dat = m;
		pv->next = pkey->next; 
		pv->prev = pkey;  
		pkey->next = pv;  
		if (pkey != *pend) (pv->next)->prev = pv;
		else *pend = pv;  
		return pv;
	}
	return NULL;  
}

void lprint(Node* pbeg) {
	Node* pv = pbeg;
	while (pv) {
		cout << pv->dat << ' ';
		pv = pv->next;
	} cout << endl;
}

void ldel(Node* pbeg) {
	Node* pv;
	while (pbeg) {
		pv = pbeg;
		pbeg = pbeg->next;
		delete pv;
	}
}