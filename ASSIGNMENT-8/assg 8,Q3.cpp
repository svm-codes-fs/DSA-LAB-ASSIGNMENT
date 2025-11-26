#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else
        cout << "Duplicate value " << val << " not allowed!\n";
    return root;
}
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
Node* deleteNode(Node* root, int val) {
    if (root == NULL)
        return root;
    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int maxDepth(Node* root) {
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    if (leftDepth > rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}
int minDepth(Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    if (root->left == NULL)
        return 1 + minDepth(root->right);
    if (root->right == NULL)
        return 1 + minDepth(root->left);
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    if (leftDepth < rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    Node* root = NULL;
    int choice, value;
    while (true) {
        cout << "\n Binary Search Tree Operations \n";
        cout << "1. Insert\n2. Delete\n3. Display Inorder\n4. Maximum Depth\n5. Minimum Depth\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 3:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Maximum Depth of BST = " << maxDepth(root) << endl;
                break;
            case 5:
                cout << "Minimum Depth of BST = " << minDepth(root) << endl;
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}

