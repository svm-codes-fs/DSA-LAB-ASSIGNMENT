#include<iostream>
using namespace std;
struct node {
    int data;
    node* left;
    node* right;
    node* parent;
    node(int d) {
        data = d;
        left = right = parent = NULL;
    }
};
node* root = NULL;
node* searchrecursive(node* temp, int k) {
    if (temp == NULL || k == temp->data)
        return temp;
    if (k < temp->data)
        return searchrecursive(temp->left, k);
    else
        return searchrecursive(temp->right, k);
}
node* searchiterative(node* temp, int k) {
    while (temp != NULL && k != temp->data) {
        if (k < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return temp;
}
node* minimum(node* temp) {
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}
node* maximum(node* temp) {
    while (temp->right != NULL)
        temp = temp->right;
    return temp;
}
node* inordersuccessor(node* temp) {
    if (temp->right != NULL)
        return minimum(temp->right);

    node* temp2 = temp->parent;
    while (temp2 != NULL && temp == temp2->right) {
        temp = temp2;
        temp2 = temp2->parent;
    }
    return temp2;
}
node* inorderpredecessor(node* temp) {
    if (temp->left != NULL)
        return maximum(temp->left);
    node* temp2 = temp->parent;
    while (temp2 != NULL && temp == temp2->left) {
        temp = temp2;
        temp2 = temp2->parent;
    }
    return temp2;
}
node* insert(node* root, int data) {
    if (root == NULL)
        return new node(data);
    if (data < root->data) {
        node* leftChild = insert(root->left, data);
        root->left = leftChild;
        leftChild->parent = root;
    } else {
        node* rightChild = insert(root->right, data);
        root->right = rightChild;
        rightChild->parent = root;
    }
    return root;
}
int main() {
	node* root = new node(50);
    root->left = new node(30);
    root->right = new node(70);
    root->left->left = new node(20);
    root->left->right = new node(40);
    root->right->left = new node(60);
    root->right->right = new node(80);
    root->left->parent = root;
    root->right->parent = root;
    root->left->left->parent = root->left;
    root->left->right->parent = root->left;
    root->right->left->parent = root->right;
    root->right->right->parent = root->right;
    int key = 40;
    if (searchrecursive(root, key))
        cout << "Recursive: found" << endl;
    else
        cout << "Recursive: not found" << endl;
    if (searchiterative(root, key))
        cout << "Iterative: found" << endl;
    else
        cout << "Iterative: not found" << endl;
    node* min = minimum(root);
    cout << "Minimum element: " << min->data << endl;
    node* max = maximum(root);
    cout << "Maximum element: " << max->data << endl;
    node* n = searchiterative(root, key);
    node* succ = inordersuccessor(n);
    node* pred = inorderpredecessor(n);
    if (succ)
        cout << "Inorder Successor of " << n->data << " is " << succ->data << endl;
    else
        cout << "No inorder successor exists" << endl;

    if (pred)
        cout << "Inorder Predecessor of " << n->data << " is " << pred->data << endl;
    else
        cout << "No inorder predecessor exists" << endl;
    return 0;
}
