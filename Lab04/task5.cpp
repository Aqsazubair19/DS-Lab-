#include<iostream>
using namespace std;

int interpolation_search(int arr[],int n ,int high, int low, int target){
   int pos;

   if(low <= high && target >=arr[low] && target <=arr[high]){
     pos = low + (  ((target - arr[low])*(high - low))   /  (arr[high]-arr[low]) );
     
     if(target > arr[pos]){
        return interpolation_search(arr,n,high,pos+1,target);
     }
     else if(target < arr[pos]){
         return interpolation_search(arr,n,pos-1,low,target);
     }
     else{
        cout<<"taget found at index: ";
        return pos;
     }
   }
   cout<<"target not found "<<endl;
   return -1;
  

}

void print_array(int arr[],int n){
    for(int i=0;i<n;i++){ 
            cout<<arr[i]<<" ";
              }
cout<<endl;

}


int main() {
     int n=10;
    int arr[n] = {1,3,7,15,20,21,50,55,75,80}; // already sorted array not uniform but program still work
    // program will run for sorted +uniform array also
    
    int target;
    cout<<"enter target elmenet: "<<endl;
    cin>>target;
    // setting high and low value to trace array and shrink 
    int low = 0; // first index value;
    int high = n-1;  // end value of array
     
    cout<<"array elements are:"<<endl;
    print_array(arr,n);
    cout<<interpolation_search(arr,n,high,low,target);
   

}
