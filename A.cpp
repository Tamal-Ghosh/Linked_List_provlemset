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
node* swappp_all(node* & head)
{
    node* first=head,*second,* prev ,*after;
    node*dummy=new node();
    prev=dummy;
    prev->next=head;
    while(first && first->next)
    {
        second=first->next;
        after=second->next;
        second->next=first;
        prev->next=second;
        first->next=after;
        prev=first;
        first=after;

    }
    return dummy->next;
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

    printList(swappp_all(head));


}