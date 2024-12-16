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

node* merge(node* &head1, node* &head2)
{
    node* head=nullptr,*temp;
    node* temp1=head1;
    node *temp2=head2;
    while(temp1!= nullptr &&  temp2!= nullptr)
    {
        if(temp1->data<temp2->data)
        {
            if(head==nullptr)
        {
        head=temp1;
        temp=temp1;
        }
        else{
        temp->next=temp1;
        temp=temp1;
        }
        temp1=temp1->next;
        }

        else{
            if(head==nullptr)
        {
        head=temp2;
        temp=temp2;
        }
        else{
        temp->next=temp2;
        temp=temp2;
        }

        temp2=temp2->next;
        }
    }
    if (temp1 != nullptr) {
        if (head == nullptr) {
            head = temp1;
        } else {
            temp->next = temp1;
        }
    }
    if (temp2 != nullptr) {
        if (head == nullptr) {
            head = temp2;
        } else {
            temp->next = temp2;
        }
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
    node* head1 = nullptr,*temp1;

    // initial list
    for(int i=0;i<3;i++){
    node* newnode = createnode();
    if(head1==nullptr)
    {
        head1=newnode;
        temp1=newnode;
    }
    else{
        temp1->next=newnode;
        temp1=newnode;
    }
    }
    printList(head1);


    node* head2 = nullptr,*temp2;
    for(int i=0;i<3;i++){
    node* newnode = createnode();
    if(head2==nullptr)
    {
        head2=newnode;
        temp2=newnode;
    }
    else{
        temp2->next=newnode;
        temp2=newnode;
    }
    }
    printList(head2);

    printList(merge(head1,head2));


}