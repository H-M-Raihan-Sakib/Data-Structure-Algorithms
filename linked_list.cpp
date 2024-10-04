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

void inserAtHead(node* &head, int val){
    node* n = new node(val);

    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);

    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool search(node* head, int k){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data == k){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deletion(node* &head, int key){
    node* temp = head;
    while(temp->next->data!=key){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

void deleteAtHead(node* &head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }
    node* todelete = head;
    head = head->next;

    delete todelete;
}

int main(){
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    inserAtHead(head, 4);
    deleteAtHead(head);
    display(head);

    return 0;
}
