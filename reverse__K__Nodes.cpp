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
        return;
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
        temp = temp ->next;
    }
    cout << endl;
}

node* reversek(node* &head, int k){

    node* prevptr= NULL;
    node* currptr = head;
    node* nextptr;
    int count = 0;
    while(currptr!=NULL && count<k){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if(nextptr!=NULL){
        head->next = reversek(nextptr,k);
    }

    return prevptr;
}

int main(){
    node* head = NULL;
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    InsertAtTail(head, 6);
    node* newhead = reversek(head,2);
    display(newhead);

}