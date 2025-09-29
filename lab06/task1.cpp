#include <iostream>
using namespace std;

class stack{
    // array
    public:

    int top = -1; // it tells ky stack mai kitny elements hai , initilize with -1 becaue already empty hai
    int arr[5];
    

  bool  push(int x){ 
     // kuch bhi push krny sy pehlycheck krna hai ky array ka pass limit hai koi bhi elementko insert krn ki ya nhi check lgana hai iska
    // overflow check
    if(top >=(5-1)){   // size out of bound  jaye arrray ki length ky te overflow hoga and we return false
        cout<<"overflow"<<endl;
        return false;
    }else{
        arr[++top] = x;  // firdt increment the top because we set out top to -1 so we have to have to inc first then add it in array 
        return true;

    } }

  void pop(){
    // underflow
    if(top <0 ){  // if there is no element in array 
     cout<<"underflow"<<endl;
     return;

    }else{
        int poppedElement = arr[top--]; // yaha sy ek ek krky top dec hota jayega or sary elements arty jayegy
        cout<<poppedElement<<endl;
           
    }
    }

  int peek(){
       // underflow
    if(top <0 ){  // if there is no element in array 
     cout<<"underflow"<<endl;
     return 0;

    }else{
        int poppedElement = arr[top];  // we only got first peek elmenet with this function
        return poppedElement;   
    }
    
  }
  
  bool isEmpty(){
    if(top< 0){
      return true;
    }
   
  }

  // int display(){
  //   for(int i=0;i<top;i++){
  //     cout<<arr[top--]<<endl;
  //   }
  // }
};


int main(){
    stack st;
    st.push(3);
    st.push(4);
    st.push(6);
    st.peek(); // 6
    st.pop(); // 6  and top--
    st.peek(); // 4
    st.pop();  // 4 , top --
    st.peek(); // 3
    st.pop(); // 3 , top -- , mow top goes underflow
    st.peek();
    return 0;
}
