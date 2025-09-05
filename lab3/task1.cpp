#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

};

int *arr;
int count;

void print_data(Node* head){
    
    Node *temp = head;
    
int j=0;    
    while(temp != NULL){
     // cout<<temp->data<<" ";
      arr[j] =temp->data;
     temp = temp->next;
     j++;
    }
    
    cout<<endl;

}

 bool ispalindrom = true;
int i;
void PrintReverse(Node* head){

    if(head == NULL){
        return;
    }

    PrintReverse(head->next);
      cout<<head->data<<" ";
     
   
     
    if(arr[i] != head->data){
       ispalindrom = false;
    }
     i++;
}

int main(){
    
    cout<<"tell me how many number you want enter"<<endl;
     cin>>count;
    
     arr = new int[count];
    
    Node *head = NULL;
    Node *tail = NULL;

     cout<<"enter numbers:"<<endl;
    for(int k=0;k<count;k++){
        int num;
        cin>>num;

         Node *new_node = new Node();
         new_node->data = num;
         new_node->next = NULL;

         if(head == NULL){
            head = new_node;
            tail = new_node;
         }
         else{
            tail->next = new_node;
            tail = new_node;

         }
        }

  print_data(head);     
    i=0;
  PrintReverse(head);

  if(ispalindrom){
        cout<<"\npalindrom"<<endl;
  }else{
    cout<<"\nnot palindrom"<<endl;
  }
   return 0;
   
}
