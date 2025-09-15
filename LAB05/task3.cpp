#include<iostream>
using namespace std;

int sumTail(int n, int total){
   
    while( n == 0){
        return total;
    }
  
   
    return sumTail(n-1,total+n);
}

int sumNonTail(int n,int total){
   
    while( n == 0){
        return total;
    }
     int result = sumNonTail(n - 1, total);
     return result + n; 
}
// comparison: 
/*
sumNonTail(3)
 → sumNonTail(2)
   → sumNonTail(1)
     → sumNonTail(0) → returns 0
     ← 0 + 1 → returns 1
   ← 1 + 2 → returns 3
 ← 3 + 3 → returns 6
*/

int main(){
    int n;
    cout<<"enter n: "<<endl;
    cin>>n;
    int total = 0;
    cout<<"sum with tail recursion of "<<n<<" "<<endl;
    cout<<sumTail(n,total) <<endl;
    
      cout<<"sum with non tail recursion of "<<n<<" "<<endl;
    cout<<sumNonTail(n,total) <<endl;
    
   
}



