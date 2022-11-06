#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next ;

    Node(int data) {
        this ->data = data;
        this->next =NULL;

    }
};
void addAtHead(Node* &head,int d) {
    Node* temp = new Node(d);
    temp->next=head;
    head=temp;

}
void print(Node* &head) {
    Node* temp =head;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void addAtTail(Node* &tail,int d) {
    Node* temp = new Node(d);
    tail->next=temp;
    tail=tail->next;
}
void addAtAnyPosition(Node* &tail,Node* &head,int position,int d) {
    if(position==1){
        addAtHead(head,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt < position-1){
        if(temp->next==NULL) {
            addAtTail(tail,d);
            return;
        }
        temp=temp->next;
        cnt++;
    }
    Node* toAdd = new Node(d);
    toAdd->next=temp->next;
    temp->next=toAdd;

}
int main() {
    Node* n1=new Node(50);
    Node* head = n1;
    Node* tail=n1;
    addAtHead(head,40);
    addAtTail(tail,60);
    addAtAnyPosition(tail,head,4,65);
    print(head);
    cout<<"Head " << head->data<<endl<<head->next<<" "<<endl;
    cout<<"Tail " <<tail->data;
    

}