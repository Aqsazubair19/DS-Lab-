#include<iostream>
using namespace std;


class Node{

    public:
    int data;
    Node* next;

};
void print_data(Node* head){
    
    Node *temp = head;
   
    while(temp != NULL){
      cout<<temp->data<<" ";
       temp = temp->next;
   
    }

     cout<<endl;

}



Node* PrintReverse_in_k_size(Node* head, int size){
  
   
    if(head == NULL){
        return NULL;
    }
    
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    int count =0;
    curr = head;
    while(count < size && curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

     if(next != NULL){ 
      head->next = PrintReverse_in_k_size(next,size);   
}
     return prev;
     
}

int main(){
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();
    Node  *fifth = new Node();
    Node *six = new Node();
    Node *seven = new Node();
    Node  *eight = new Node();
    
   head->data = 1;      head->next = second;
   second->data = 2;    second->next = third;
   third->data=3;       third->next = fourth;
   fourth->data = 4;    fourth->next = fifth;
   fifth->data=5;       fifth->next = six;
   six->data=6;         six->next = seven;
   seven->data=7;       seven->next = eight;
   eight->data=8;       eight->next = NULL;

int size;

 cout<<"enter size in which you want to print data: "<<endl;
 cin>>size;

   print_data(head);

   cout<<"data after reversing in size k:"<<endl;
  head = PrintReverse_in_k_size(head,size);
     print_data(head);
return 0;
}
