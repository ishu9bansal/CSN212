#include <iostream>
using namespace std;
struct node{
	int d;
	bool c;		// black:0(false)	red:1(true)
	node *l, *r, *p;
	node(int data=0) : d(data), c(false), l(NULL), r(NULL), p(NULL){}
};
// node* insert(node* root, node* x){	// first implementation
// 	// it returns the root of the tree, which may be changed in this procedure.
// 	if(root==NULL)	return root=x;
// 	node* temp;
// 	if(x->d<root->d)	root->l = temp = insert(root->l,x);
// 	else				root->r = temp = insert(root->r,x);
// 	temp->p = root;
// 	return root;
// }
node* insert(node* &root, node* x){		// little changed implementation
	// it returns the root of the tree, which may be changed in this procedure.
	if(root==NULL)	return root=x;
	node* temp;
	if(x->d<root->d)	temp = insert(root->l,x);
	else				temp = insert(root->r,x);
	temp->p = root;
	return root;
}
node* insert(node* &root, int x){
	node* nx = new node(x);
	return insert(root,nx);
}
void inorder(node* root){
	if(!root)	return;
	inorder(root->l);
	cout<<root->d<<' ';
	inorder(root->r);
	return;
}
void preorder(node* root){
	if(!root)	return;
	cout<<root->d<<' ';
	preorder(root->l);
	preorder(root->r);
	return;
}
node* search(node* x, int k){
	if(!x||x->d==k)	return x;
	if(k<x->d)	return search(x->l,k);
	else		return search(x->r,k);
}
node* minimum(node* x){
	while(x&&x->l)	x = x->l;
	return x;
}
node* maximum(node* x){
	while(x&&x->r)	x = x->r;
	return x;
}
node* successor(node* x){
	if(!x)	return x;
	if(x->r)	return minimum(x->r);
	node* y = x->p;
	while(y&&x==y->r){
		x = y;	y = y->p;
	}
	return y;
}
node* delete_node(node* &root, node* x){
	node* child;
	if(!x->l&&!x->r)	child = NULL;
	else if(!x->l){
		child = x->r;
		x->r->p = x->p;
	}
	else if(!x->r){
		child = x->l;
		x->l->p = x->p;
	}
	else{
		node* y = successor(x);
		delete_node(x,y);
		y->p = x->p;	y->l = x->l;	y->r = x->r;
		x->l->p = y;	x->r->p = y;	child = y;
	}
	if(!x->p)			root = child;
	else if(x==x->p->l)	x->p->l = child;
	else				x->p->r = child;
	return root;
}
node* leftRotate(node* &root, node* x){
	node* y = x->r;
	x->r = y->l;
	if(y->l)	y->l->p = x;
	y->p = x->p;
	if(!x->p)			root = y;
	else if(x==x->p->l)	x->p->l = y;
	else				x->p->r = y;
	y->l = x;
	x->p = y;
	return root;
}
node* rightRotate(node* &root, node* x){
	node* y = x->l;
	x->l = y->r;
	if(y->r)	y->r->p = x;
	y->p = x->p;
	if(!x->p)			root = y;
	else if(x==x->p->l)	x->p->l = y;
	else				x->p->r = y;
	y->r = x;
	x->p = y;
	return root;
}
int main() {
	node* tree = NULL;
	int c;
	for(int i=0; i<20; i++){
		c = rand()%100;
		insert(tree,c);		// random BST generation
		cout<<c<<' ';		// random no.s output order
	}
	cout<<endl;
	inorder(tree);			// tree inorder
	cout<<endl;
	preorder(tree);			// tree preorder
	cout<<endl;
	
	node* search_result = search(tree,c);	// search check
	cout<<search_result<<endl;
	cout<<search_result->d<<endl;
	cout<<search(tree,50)<<endl;
	
	node* min = minimum(tree);			// min max check
	node* max = maximum(tree);
	
	cout<<min->d<<endl;		// 15
	cout<<max->d<<endl;		// 93
	
	cout<<minimum(max)->d<<endl;	// 86
	cout<<minimum(min)->d<<endl;	// 15
	
	node* sr = search(tree,72);
	
	cout<<successor(search_result)->d<<endl;	// 40
	cout<<successor(tree)->d<<endl;				// 86
	cout<<successor(max)<<endl;					// 0
	cout<<successor(min)->d<<endl;				// 21
	cout<<successor(sr)->d<<endl;				// 77
	
	delete_node(tree,sr);
	inorder(tree);	cout<<endl;		// 72
	delete_node(tree,max->l);
	inorder(tree);	cout<<endl;		// 86
	cout<<max->l->d<<max->l->p->d<<endl;	// 9293
	delete_node(tree,tree->l);
	inorder(tree);	cout<<endl;		// 77
	cout<<tree->l->d<<tree->l->p->d<<endl;	// 1583
	delete_node(tree,tree->l);
	inorder(tree);	cout<<endl;		// 15
	cout<<tree->l->d<<tree->l->p->d<<endl;	// 3583
	delete_node(tree,tree->l->p->l);
	inorder(tree);	cout<<endl;		// 35
	cout<<tree->l->d<<tree->l->p->d<<endl;	// 3683
	
	cout<<tree->l->d<<tree->l->l->d<<tree->l->r->d<<tree->l->r->l->l<<tree->l->r->l->d<<endl;
	// 362149040
	delete_node(tree,tree);
	inorder(tree);	cout<<endl;		// 83
	cout<<tree->d<<tree->l->d<<tree->r->d<<tree->l->p->d<<tree->r->p->d<<endl;	// 8636938686
	
	preorder(tree);	cout<<endl;
	
	leftRotate(tree,tree->l);		// rotation check
	rightRotate(tree,tree->r);
	
	preorder(tree);	cout<<endl;
	
	cout<<tree->l->d<<tree->r->d<<endl;		// 4992
	
	return 0;
}
