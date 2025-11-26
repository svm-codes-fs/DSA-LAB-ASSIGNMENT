#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = NULL;
void insertAtEnd(int value){
	Node* newnode = new Node();
	 newnode->data = value;
    newnode->next = NULL;
	if (head==NULL){
		head=newnode;
		return;
	}
	Node* temp;
	temp=head;
	while (temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
}
void display(){
	Node* temp;
	temp=head;
	if (head==NULL){
		cout<<"list is empty";
	}
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL\n";
}
void findMiddle() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle element: " << slow->data << endl;
    
}
int main(){
 int n, value;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertAtEnd(value);
    } cout << "Linked List: ";
    display();
    findMiddle();
    return 0;
}
