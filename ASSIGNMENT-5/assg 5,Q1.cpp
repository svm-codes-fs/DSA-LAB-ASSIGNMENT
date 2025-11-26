#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = NULL;
void insertAtBeginning(int value) {
    Node* newnode = new Node();
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    cout << "Node inserted at the beginning.\n";
}
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
void insertAtPos(int value,int Pos){
	Node* newnode = new Node();
	 newnode->data = value;
    newnode->next = NULL;
    if (Pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }
    	Node* temp;
	temp=head;
	if (temp==NULL){
		cout<<"position out of range \n";
	}
	int i=1;
	while (i<Pos-1){
		temp=temp->next;
		i++;
	}
	newnode->next=temp->next;
	temp->next=newnode;
}
void deletefrombeginning(){
	Node* temp;
	temp=head;
	if (head==NULL){
		cout<<"list is empty";
	}
	head=temp->next;
	delete temp;
}
void deletefromend(){
	Node* temp;
	temp=head;
	Node* prev;
	prev=head;
	if (head==NULL){
		cout<<"list is empty";
		return;
	}
	if (head->next==NULL){
		delete head;
		head=NULL;
		return;
	}
	while(temp->next!=NULL){
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
	delete temp;
}
void deleteNode(int value){
	Node* temp;
	temp=head;
	Node* prev;
	prev=head;
	int i=1;
	if (head==NULL){
		cout<<"list is empty";
		return;
	} 
	while(temp->data!=value){
		prev=temp;
		temp=temp->next;
		i++;
	}
	prev->next=temp->next;
	delete temp;
}
void searchnode(int value){
	Node* temp;
	temp=head;
	int count=0;
	while (temp!=NULL){
	if (temp->data==value){
		temp=temp->next;
		count++;
	}}
	cout<<"found at"<<count;
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
	cout<<"NULL";
}
int main(){
	 int choice, value, target;
 do {
        cout << "\n=== Singly Linked List Menu ===\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at specific position\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete specific node\n";
        cout << "7. Search node\n";
        cout << "8. Display list\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                int Pos;
                cin >> Pos;
                insertAtPos(value, Pos);
                break;
            case 4:
                deletefrombeginning();
                break;
            case 5:
                deletefromend();
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(value);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                searchnode(value);
                break;
            case 8:
                display();
                break;
            case 9:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 9);
    return 0;
}

