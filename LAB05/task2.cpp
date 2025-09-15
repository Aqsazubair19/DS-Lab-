#include<iostream>
using namespace std;
   
// direct recursion:
int print_numbers(int n){  // part 1

    if(n==0){
       return 0;
    }else{
     cout << n << " ";
    return  print_numbers(n-1);
   
    }
}

/// indirect recursion :
int functionB(int n);   // part 2
int functionA(int n){  
    if(n==0){
       return 0;
    }else{
     cout << n << " ";
    return  functionB(n-1);
   
    }
}

int functionB(int n){
     if(n==0){
       return 0;
    }else{
     cout << n << " ";
    return  functionA(n-1);
   
    }
}

int main(){
    int n;
    cout<<"enter n: "<<endl;
    cin>>n;
    cout<<"print number : "<<endl;
    cout<< print_numbers(n)<<endl;
    
    cout<<"Function A: "<<endl;
    cout<<functionA(n)<<endl;
    
    cout<<"Function B: "<<endl;
    cout<<functionB(n)<<endl;

}



