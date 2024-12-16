#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

node* createnode() {
    int val;
    cout << "GIVE VALUE: ";
    cin >> val;
    node* newnode = new node();
    newnode->data = val;
    newnode->next = nullptr;
    return newnode;
}

void printList(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtBeginning(node*& head) {
    node* newnode = createnode();
    newnode->next = head;
    head = newnode;
}

void insertAtEnd(node*& head) {
    node* newnode = createnode();
    if (head == nullptr) {
        head = newnode;
        return;
    }
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertAtPosition(node*& head, int pos) {
    node* newnode = createnode();
    if (pos == 1) {
        insertAtBeginning(head);
        return;
    }

    node* temp = head;
    int i = 1;
    while (i < pos - 1 ) {
        temp = temp->next;
        i++;
    }
        newnode->next = temp->next;
        temp->next = newnode;
    return;
}


void insertAfterValue(node*& head, int val) {
    node* newnode = createnode();
    node* temp = head;
    while (temp->data!= val ) {
        temp = temp->next;
    }
        newnode->next = temp->next;
        temp->next = newnode;
}

void insertBeforeValue(node*& head, int val) {
    node* newnode = createnode();
    node* temp = head;
    while (temp->next->data!= val ) {
        temp = temp->next;
    }
        newnode->next = temp->next;
        temp->next = newnode;
    return;
}

void deleteAtStart(node *& head)
{
    node * temp;
    temp=head;
    head=temp->next;
    delete temp;
}

void deleteAtEnd(node *& head)
{
    node * temp,*prvnode;
    temp=head;
    while(temp->next!=nullptr)
    {
        prvnode=temp;
        temp=temp->next;
    }
    prvnode->next=nullptr;
    delete temp;
}


void deleteAtanypos(node *& head)
{
    int pos,i=1;
    cout<<"Position: ";
    cin>>pos;
    node * temp,*delete_node;
    temp=head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    delete_node=temp->next;
    temp->next=delete_node->next;
    delete delete_node;
}


void deleteAfterValue(node *& head,int val)
{
    node * temp,*delete_node;
    temp=head;
    while(temp->data!=val)
    {
        temp=temp->next;
    }
    delete_node=temp->next;
    temp->next=delete_node->next;
    delete delete_node;
}

void deleteBeforeValue(node *& head,int val)
{
    node * temp,*delete_node,*prvnode;
    temp=head;
    while(temp->next->data!=val)
    {
        prvnode=temp;
        temp=temp->next;
        cout<<prvnode->data<<endl;
    }
    delete_node=prvnode->next;
    prvnode->next=delete_node->next;
    delete delete_node;
}

int main() {
    node* head = nullptr,*temp;

    // initial list
    for(int i=0;i<5;i++){
    node* newnode = createnode();
    if(head==nullptr)
    {
        head=newnode;
        temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
    }
    printList(head);
int val,choice;
    
    while (true) {
        cout << "\nMenu:"<<endl;
        cout << "1. Insert at beginning"<<endl;
        cout << "2. Insert at end"<<endl;
        cout << "3. Insert at position"<<endl;
        cout << "4. Insert before a value"<<endl;
        cout << "5. Insert after a value"<<endl;
        cout << "6. Delete at start"<<endl;
        cout << "7. Delete at end"<<endl;
        cout << "8. Delete at position"<<endl;
        cout << "9. Delete before a given value"<<endl;
        cout << "10. Delete after a given value"<<endl;
        cout << "11. Traverse list"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertAtBeginning(head);
                printList(head);
                break;
            case 2:
                insertAtEnd(head);
                printList(head);
                break;
            case 3:
            int pos;
                cout << "Enter position: ";
                cin >> pos;
                insertAtPosition(head, pos);
                printList(head);
                break;
            case 4:
                cout<<"VALUE: ";
                cin>>val;
                insertBeforeValue(head,val);
                printList(head);
                break;
            case 5:
                cout<<"VALUE: ";
                cin>>val;
                insertAfterValue(head,val);
                printList(head);
                break;
            case 6:
            
                deleteAtStart(head);
                printList(head);
                break;
            case 7:
                deleteAtEnd(head);
                printList(head);
                break;
            case 9:
                cout<<"VALUE: ";
                cin>>val;
                deleteBeforeValue(head,val);
                printList(head);
                break;
            case 10:
                cout<<"VALUE: ";
                cin>>val;
                deleteAfterValue(head,val);
                printList(head);
                break;
            case 11:
                printList(head);
                break;
            case 0:
                cout << "Exiting program." << endl;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    

    return 0;
}
