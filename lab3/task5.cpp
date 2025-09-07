#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
    }

};

class list{
    Node* head ;
    Node* tail;

    public:
    list(){
        head = tail = NULL;
    }
  

        // insert at first:
    void push_front(int val){
        Node* newnode = new Node(val);

        if(head == NULL){
            head = tail = newnode;
            return;
        }
        else{
            newnode->next = head;
            head = newnode;

        }
    }

    void print(){

        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    // conversion of singly  tp doubly list:
    void convert_to_doubly(){
        Node* temp = head;
        Node* PREV= NULL;

        while(temp != NULL){
            if(temp == head){
              temp->prev =NULL;
              PREV = temp;
              temp = temp->next;
            }
            else{
               temp->prev = PREV;
               PREV = temp;
               temp = temp->next;

            }
        }

    }
// similar function to just show doubly linked list printing:   
    void print_doubly(){
        Node* temp = head;
        cout<<"NULL";

        while(temp != NULL){
            cout<<"<-"<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

   // conversion of singly to circular: 
    void covert_to_circular(){
         if (head == NULL) return;

        Node* temp = head;

        while(temp->next != NULL){
            temp = temp->next;  
        }
        temp->next = head;
        return;
    }

    // print function to show circular link list:
    void print_circular(){

        if(head == NULL){
            return;
        }

        cout<<head->data<<"->";
        Node* temp = head->next;

        while(temp != head){
            cout<<temp->data<<"->";
            temp = temp->next;

        }

        cout<<temp->data<<endl;
        
    }
    
};

int main(){
    list l1;
    list l2;
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);
    cout<<"singly link list"<<endl;
    l1.print();

    cout<<" conversion from sll to doubly link list:"<<endl;
    l1.convert_to_doubly();
    l1.print_doubly();


    l2.push_front(3);
    l2.push_front(2);
    l2.push_front(1);
   cout<<"singly link list"<<endl;
    l2.print();

     cout<<" conversion from sll to circular link list:"<<endl;
    l2.covert_to_circular();
    l2.print_circular(); 

}
