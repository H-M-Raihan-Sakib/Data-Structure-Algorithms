#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void InsertAtHead(node* &head, int val){
    node* n = new node(val);
    node* temp= head;
    if(head==NULL){
        n->next=n;
        head=n;
        return ;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=n;
    n->next=head;
    head = n;

}


void InsertAtTail(node* &head, int val){
    node* n = new node(val);

    if(head==NULL){
        InsertAtHead(head, val);
        return ;
    }

    node* temp= head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}


void deleteAtHead(node* &head){
    node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    node* todelete = head;
    temp->next = head->next;
    head=head->next;
    delete todelete;
}


void deletion(node* &head, int pos){
    if(pos==1){
        deleteAtHead(head);
        return ;
    }

    node* temp = head;
    int count = 1;
    while(count!=pos-1){
        temp = temp->next;
        count++;
    }

    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;

}

void display(node* &head){
    node* temp = head;
    do{
        cout << temp->data <<" ";
        temp = temp->next;
    }while(temp!=head);
    cout << endl;
}


int main(){
    node* head =NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    deletion(head,1);
    display(head);

}
