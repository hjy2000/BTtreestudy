#include<iostream>
using namespace std;

typedef struct btnode
{
	char data;
	btnode* lc, * rc;
}btnode, * ptr;

void preorder(ptr p)
{
	if (p!=NULL) {
		
		cout << p->data;
		preorder(p->lc);
		preorder(p->rc);
	}
	
}

char x;
ptr createGJ()
{
	ptr p;
	cin >> x;
	if (x == '0')return NULL;
	p = new btnode;
	p->data = x;
	p->lc = createGJ();
	p->rc = createGJ();
	return p;
}
ptr createT(char a[],char b[],int i,int j,int s,int t)
{
	ptr p;int k;
	if (i > j)return NULL;
	p = new btnode;
	p->data = a[i];
	k = s;
	while ((k <= t) && (b[k] != a[i]))k++;
	if (k > t)return NULL;
	p->lc = createT(a, b, i + 1, i + k - s, s, k - 1);
	p->rc = createT(a, b, i + k - s + 1, j, k + 1, t);
	return p;
}

void inorder(ptr p)
{
	if (p != NULL) {
		inorder(p->lc);
		
		cout << p->data;
		inorder(p->rc);
	}
}


void postorder(ptr p)
{
	if (p != NULL) {
		postorder(p->lc);
		

		postorder(p->rc);
		cout << p->data;
	}
}
int main()
{
	char a[] = {'a','b','c','d','e','f','g','h'};
	char b[] = {'b','d','c','e','a','g','f','h'};
	ptr p;ptr q;
	p = createGJ();
	q = createT(a, b, 0,7, 0, 7);

	preorder(p);
	cout << endl;
	preorder(q);
	cout << endl;
	inorder(p);
	cout << endl;
	inorder(q);
	cout << endl;
	postorder(p);
	cout << endl;
	postorder(q);
	cout << endl;
	return 0;
}
