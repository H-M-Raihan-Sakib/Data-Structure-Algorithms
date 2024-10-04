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

void InsertAtTail(node* &head, int val){

    node* n = new node(val);

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

int length(node* &head){
    node* temp = head;
    int count=0;

    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    return count ;
}

node* kappend(node* &head, int k){

    node* newHead;
    node* newTail;
    node* tail = head;

    int l = length(head);
    int count = 1;

    while(tail->next!=NULL){
        if(count==l-k){
            newTail = tail;
        }
        if(count==l-k+1){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }

    newTail ->next = NULL;
    tail->next = head;

    return newHead;
}

void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    node* head = NULL;
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    InsertAtTail(head, 6);
    
    node* newHead = kappend(head,3);
    display(newHead);
}