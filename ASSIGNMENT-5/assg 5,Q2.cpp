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
bool deleteNode(int key){
	Node* temp;
	temp=head;
	Node* prev;
	prev=head;
	int i=1;
	if (head==NULL){
		cout<<"list is empty";
		return false;
	} 
	if (head->data==key){
		head=head->next;
		delete temp;
		return true;
	}
	while(temp != NULL && temp->data!=key){
		prev=temp;
		temp=temp->next;
		i++;
	}
	 if (temp == NULL){                      
        return false;}
	prev->next=temp->next;
	delete temp;
	return true;
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
 int n, value, key;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertAtEnd(value);
    }
    cout << "Enter the key to delete all occurrences: ";
    cin >> key;
    int count = 0;
    while (deleteNode(key)) 
        count++;
    cout << "\nNumber of occurrences deleted: " << count << endl;
    cout << "Updated list: ";
    display();
    return 0;
}
