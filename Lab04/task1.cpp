#include<iostream>
using namespace std;

void linear_Search(int arr[], int n , int targetvalue){
    for(int i=0;i<n;i++){
        if(arr[i]==targetvalue){
            cout<<"Found target value "<<arr[i]<<" at index "<<i<<endl;
            return;
        }
    }
    cout<<"target value not found"<<endl;
}



int main(){
     int n ;
    cout<<"enter how many elemnts you want to enter :"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter elements: "<<endl;
    
    for(int i=0;i<n;i++){
      cout<<"element "<<i+1<<": ";
      cin>>arr[i]; 
      cout<<endl;
    } 

    int target_element;
    cout<<"enter target element: "<<endl;
    cin>>target_element;


    linear_Search(arr,n,target_element);
}
