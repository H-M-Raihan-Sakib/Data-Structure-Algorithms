#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void InsertAtHead(node* &head, int val){


    node* n = new node(val);

    n->next = head;
    if(head!=NULL){
        head->prev = n;
    }

    head = n;
}

void InsertAtTail(node* &head, int val){
    if(head==NULL){
        InsertAtHead(head, val);
        return ;
    }

    node* n= new node(val);
    node* temp = head;

    while(temp->next !=NULL){
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;

}


void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout <<endl;
}

void deleteAtHead(node* &head){
    node* todelete = head;

    head = head->next;
    head->prev = NULL;

    delete todelete;
}


void deletion(node* &head, int pos){
    if(pos==1){
        deleteAtHead(head);
        return ;
    }

    node* temp = head;
    int count = 1;
    while(temp!=NULL && count!=pos){
        temp = temp->next;
        count++;
    }

    temp->prev->next = temp->next;
    if(temp->next!=NULL){
        temp->next->prev = temp->prev;
    }

    delete temp;
}

int main(){
    node* head = NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    display(head);
    InsertAtHead(head,0);
    display(head);
    deletion(head, 2);
    deleteAtHead(head);
    display(head);

    return 0;
}