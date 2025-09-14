#include<iostream>
using namespace std;


void bubble_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j+1],arr[j]);
            }
        }
    }
}

void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
              }
cout<<endl;

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
 
    cout<<"array elements are:"<<endl;
    print_array(arr,n);
    bubble_sort(arr,n);
    cout<<"Sorted Array: "<<endl;
    print_array(arr,n);

}
