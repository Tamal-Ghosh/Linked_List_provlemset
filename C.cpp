#include<bits/stdc++.h>
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

node* dublicate_Revoval(node* head){
    node* temp=head;
    while(temp->next!=nullptr){
        if(temp->data==temp->next->data)
        {
            node* dublicate=temp->next;
            temp->next=dublicate->next;
        }
        else
        temp=temp->next;
    }
    return head;
}


void printList(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node* head = nullptr,*temp;

    // initial list
    for(int i=0;i<6;i++){
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

    printList(dublicate_Revoval(head));


}