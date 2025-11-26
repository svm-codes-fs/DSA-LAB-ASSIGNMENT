#include<iostream>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
	node(int d){
		this->data=d;
		this->left=NULL;
		this->right=NULL;
	}
};
struct node*root =NULL;
	void inorder(node* temp){
		if (temp!=NULL){
		inorder(temp->left);
		cout<<temp->data<<" ";
		inorder(temp->right);}
	}
	void preorder(node* temp){
		if (temp!=NULL){
		cout<<temp->data<<" ";
		preorder(temp->left);
		preorder(temp->right);}
	}
	void postorder(node* temp){
			if(temp!=NULL){
		postorder(temp->left);
		postorder(temp->right);
		cout<<temp->data<<" ";}
	}
int main(){
node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout << "Inorder traversal: ";
    inorder(root);
    cout << "\nPreorder traversal: ";
    preorder(root);
    cout << "\nPostorder traversal: ";
    postorder(root);
    cout << endl;
    return 0;
}
