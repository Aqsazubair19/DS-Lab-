#include<iostream>
using namespace std;

int ackermann(int m, int n){
    if(m == 0){
        return n+1;
    }
    else if (m >0 && n==0){
        return ackermann(m-1, 1);
    }
    else if( m>0 && n>0){
        return ackermann(m-1, ackermann(m, n-1));
    }
    return 0;
}

int main(){
    int n,m;
    cout<<"enter n: "<<endl;
    cin>>n;
    cout<<"enter m: "<<endl;
    cin>>m;
    
    
    cout<<"Ackermann "<<ackermann( m,  n) <<endl;
    
     
    
    
   
}



