#include<iostream>
#include <utility> 
using namespace std;

class Node_A{

    public:
    int data;
    Node_A* next;

};


// sorting of two list and ,erging them in 1 list 
Node_A* sorting_of_twoList(Node_A* head_A , Node_A *head_B){  

    Node_A *temp ; 
    Node_A *tail = NULL;
 
// set first elemnt at head 
    if(head_A->data < head_B->data){   //1< 2
        temp = head_A;
        head_A = head_A->next;
        tail = temp;
    }else{
       temp = head_B;
       head_B = head_B->next;
       tail = temp;
    }

    // if one of the list get empty emaing elemnet will merge at the end 
    if (head_A != NULL) {
    tail->next = head_A;
}
if (head_B != NULL) {  // null <6
    tail->next = head_B;
}
  
   // sorting after 1st elemnt set to head:
    while(head_A != NULL && head_B != NULL){
    if(head_A->data < head_B->data){    // 3< 2, 3<4 , 5<4 , 5<6 
        tail->next = head_A;
        head_A = head_A->next;
    }
    else{
        tail->next = head_B;
        head_B = head_B->next;
       
    }
     tail = tail->next;
    }
    return temp;
}

 void print_data(Node_A* head_A){
    
    Node_A *temp = head_A;
    
// int i=0;    
    while(temp != NULL){
      cout<<temp->data<<" ";
      //arr[i] =temp->data;
     temp = temp->next;
    //  i++;
    }
    
    cout<<endl;

}

int main(){

    Node_A * head_A = new Node_A();
    Node_A * second_A = new Node_A();
    Node_A * third_A = new Node_A();
   
    head_A->data = 1;    head_A->next = second_A ;
    second_A->data = 3;  second_A->next = third_A;
    third_A->data=5;     third_A->next = NULL; 

    print_data(head_A);

    Node_A * head_B = new Node_A();
    Node_A * second_B = new Node_A();
    Node_A * third_B = new Node_A();
  
    head_B->data = 2;    head_B->next = second_B ;
    second_B->data = 4;  second_B->next = third_B;
    third_B->data=6;     third_B->next = NULL; 

    print_data(head_B);

  Node_A* mergedHead = sorting_of_twoList(head_A, head_B);
cout << "data after sorting:" << endl;
print_data(mergedHead);

}
