#include <iostream>
using namespace std;
struct node{
	int d;
	node *l, *r, *p;
	node(int data=0) : d(data), l(NULL), r(NULL), p(NULL){}
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
int main() {
	node* tree = NULL;
	int c;
	for(int i=0; i<20; i++){
		c = rand()%100;
		insert(tree,c);
		cout<<c<<' ';
	}
	cout<<endl;
	inorder(tree);
	cout<<endl;
	preorder(tree);
	cout<<endl;
	node* search_result = search(tree,c);
	cout<<search_result<<endl;
	cout<<search_result->d<<endl;
	cout<<search(tree,50)<<endl;
	return 0;
}
