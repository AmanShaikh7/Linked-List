//similar as singly linked list bs isme node mai ek aur chiz capsuled hoti hai 
//which is pointer to previous node 
//so the node structure is like : prev | data | next 
#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
        
    }
    ~Node() {
        int val = this->data;
        if(next!=NULL) {
            delete next;
            next =NULL;
        }
        cout<<"Memory free for node with data "<<val<<endl;
    }
};
//traersing a linked list 
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
//getting length of linked list
int getLen(Node* &head) {
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
//insert at head
void insertAtHead(Node* &head,int d) {
    Node* temp = new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
// insert at tail
void insertAttail(Node* &tail,int d) {
    Node* temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
//insertAtany position
void addAtAnyPosition(Node* &tail,Node* &head,int position,int d) {
    if(position==1){
        insertAtHead(head,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt < position-1){
        if(temp->next==NULL) {
            insertAttail(tail,d);
            return;
        }
        temp=temp->next;
        cnt++;
    }
    Node* toAdd = new Node(d);
    toAdd->next=temp->next;
    temp->next->prev=toAdd;
    temp->next=toAdd;
    toAdd->prev=temp;

}
void deleteNode(int position,Node* &head) {
        if(position==1) {
            Node* temp = head;
            temp->next->prev=NULL;
            head=temp->next;
            temp->next=NULL;
            delete temp;
        }
        else {
            Node* curr=head;
            Node* prev=NULL;
            int cnt=1;
            while( cnt < position) {
                prev=curr;
                curr=curr->next;
                cnt++;
            }
            curr->prev=NULL;
            prev->next=curr->next;
            curr->next=NULL;
            delete curr;


        }
    }
int main() {
    Node* n1 = new Node(10);
    Node* head= n1;
    Node* tail=n1;
    print(head);
    cout<<"Length of the linked list is :"<<getLen(head)<<endl;;
    insertAtHead(head,5);
    print(head);
    cout<<"Length of the linked list is :"<<getLen(head)<<endl;;
    insertAttail(tail,15);
    print(head);
    cout<<"Length of the linked list is :"<<getLen(head)<<endl;;
    addAtAnyPosition(tail,head,3,50);
    print(head);
    cout<<"Length of the linked list is :"<<getLen(head)<<endl;;

    deleteNode(4,head);
    print(head);
    cout<<"Head "<<head->data<<endl;;
    cout<<"Tail "<<tail->data<<endl;
    return 0;
}