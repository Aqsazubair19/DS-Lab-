// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int target){
    int start = 0; 
    int end = n-1;
    while(start <=end ){
    int mid = (start+end) /2;
        if(target> arr[mid]){
            start = mid+1;
        }
        else if(target< arr[mid]){
            end = mid-1;
        }
        else{
            cout<<"target element found at index ";
            return mid;
        }
    }
    cout<<"target not found"<<endl;
    return -1;
}

void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int curr = arr[i];
        int prev = i-1;
    while(prev >=0 && arr[prev] > curr){
        arr[prev+1] = arr[prev];
        prev--;
    }    
    arr[prev+1] = curr;
    }
}



void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
              }
cout<<endl;

}
int main() {
    int n ;
    cout<<"enter how many elemnts you want to enter :"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter elements: "<<endl;
    int target;
    for(int i=0;i<n;i++){
      cout<<"element "<<i+1<<": ";
      cin>>arr[i]; 
      cout<<endl;
    }
    cout<<"enter target elmenet: "<<endl;
    cin>>target;
 
 
    cout<<"array elements are:"<<endl;
    print_array(arr,n);
    insertion_sort(arr,n);
    cout<<"sorted array elements are: "<<endl;
    print_array(arr,n);
    cout<< binary_search(arr,n,target)<<endl;
    
    
    

    return 0;
}
