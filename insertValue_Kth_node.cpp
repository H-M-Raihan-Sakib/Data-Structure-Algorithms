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

void InsertAtTail(node* &head, int value){
    node* n = new node(value);

    if(head==NULL){
        head = n;
        return ;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout << endl;
}

void InsertAtPosition(node* &head, int pos, int value) {
    node* n = new node(value);

    if (pos == 0) {
        n->next = head;
        head = n;
        return;
    }

    node* temp = head;
    int c = 0;

    while (temp != NULL && c < pos - 1) {
        temp = temp->next;
        c++;
    }

    n->next = temp->next;
    temp->next = n;
}


int main(){
    node* head = NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    InsertAtPosition(head, 2, 3);

    display(head);
}