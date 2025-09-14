#include<iostream>
using namespace std;


int shell_sort(int arr[],int n){
     int comparison =0;
    for(int gap =n/2 ; gap>=1;gap=gap/2){
       for(int j =gap; j<n; j++){
        for(int i=j-gap; i>=0; i= i-gap){
          comparison++;
            if(arr[i]> arr[i+gap]){
                swap(arr[i],arr[i+gap]);
            }
            else{
                break;
            }
        }
       } 
    }
     return comparison;
}

int bubble_sort(int arr[],int n){
    int comparison = 0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
    comparison++;
            if(arr[j]>arr[j+1]){
                swap(arr[j+1],arr[j]);
            }
        }
    }
     return comparison;
}

int insertion_sort(int arr[],int n){
    int comparison = 0;
    for(int i=1; i<n; i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0){
            comparison++; 
            if(arr[prev] > curr){
                arr[prev+1] = arr[prev];
                prev--;
            } else {
                break;
            }
        }
        arr[prev+1] = curr;  
    }
    return comparison;
}




void print_array(int arr[],int n){
    for(int i=0;i<n;i++){ 
            cout<<arr[i]<<" ";
              }
cout<<endl;

}

int main() {
     int n=9;
    int arr1[n] = {2,7,9,5,23,29,15,19,31};  // in this array shell sort
     int arr2[n], arr3[n];

    // copy arrays for fair test
    for(int i=0;i<n;i++){
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }   

   


     cout<<"Original array:"<<endl;
    print_array(arr1,n);

    int c1 = bubble_sort(arr1,n);
    cout<<"\nBubble Sort result:"<<endl;
    print_array(arr1,n);
    cout<<"Comparisons = "<<c1<<endl;

    int c2 = insertion_sort(arr2,n);
    cout<<"\nInsertion Sort result:"<<endl;
    print_array(arr2,n);
    cout<<"Comparisons = "<<c2<<endl;

    int c3 = shell_sort(arr3,n);
    cout<<"\nShell Sort result:"<<endl;
    print_array(arr3,n);
    cout<<"Comparisons = "<<c3<<endl;
}
    




