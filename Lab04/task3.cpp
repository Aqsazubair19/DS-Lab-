#include<iostream>
using namespace std;


/*
// selection srt: 
1) firt we assume complete array as un unsorted array 
2) then we set first element of array to be smallest index 
3) then in j loop we start comparing from i+1 (next elements of arry)
4) and compare one by one al elements with smallestindex 
5)if array[j] element is smallest than smallestindex element then we store smallestindex = j value
6) after coming ut fro j loop we swap arr[i] value with smallest index value if its change its swaps the smallest value at first
7) if smalestindex is not chnage then its bassicaly swap the smae selemet with itself 

*/

void selection_sort(int arr[], int n){

    for(int i=0;i<n-1;i++){
        int smallestindex = i; // usorted array ka starting element hoga 
        for(int j=i+1;j<n;j++){  // j shpuld start from 2nd element element of array beccause we want to find smallest element and replace it with smallest index
          if(arr[j] < arr[smallestindex]){
            smallestindex = j;
          }
        }
        swap(arr[i],arr[smallestindex]);
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
    selection_sort(arr,n);
    cout<<"Sorted Array: "<<endl;
    print_array(arr,n);
}
