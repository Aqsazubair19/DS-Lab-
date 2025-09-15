#include<iostream>
using namespace std;


int calculateFactorial(int n){

    if(n==1){
       return n;
    }else{
  
     return n* calculateFactorial(n-1);
    }
}

int main(){
    int n;
    cout<<"enter n: "<<endl;
    cin>>n;
    cout<<"factorial of "<<n<<" "<<calculateFactorial(n);

}
